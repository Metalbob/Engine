#include "stdafx.h"
#include "Game.h"

#include "Logger.h"

#include <GL/glew.h>

#include <SDL/SDL.h>

#include "glm/glm/mat4x4.hpp"
#include "glm/glm/vec3.hpp"
#include "glm/glm/vec4.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

#include "Program.h"

#include "VertexBufferObject.h"
#include "VertexArrayObject.h"

GLfloat CubeArray[48] = {
	1.0f, 0.0f, 0.0f, -1.0f, 1.0f, -1.0f,
	1.0f, 0.0f, 1.0f, -1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, -1.0f, -1.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f, 1.0f, -1.0f,
	1.0f, 1.0f, 1.0f, 1.0f, -1.0f, -1.0f
};

GLuint IndiceArray[36] = {
	0,1,2,2,1,3,
	4,5,6,6,5,7,
	3,1,5,5,1,7,
	0,2,6,6,2,4,
	6,7,0,0,7,1,
	2,3,4,4,3,5
};

float vertices[] = { -0.5, -0.5,   0.0, 0.5,   0.5, -0.5 };

float square[18] = {
	-0.5f, -0.5f, 0.0f, // Coin en bas à gauche
	-0.5f, 0.5f, 0.0f, // Coin en haut à gauche
	0.5, 0.5f, 0.0f, // Coin en haut à droite

	0.5f, -0.5f, 0.0f, // Coin en bas à droite
	-0.5f, -0.5f, 0.0f, // Coin en bas à gauche
	0.5f, 0.5f, 0.0f // Coin en haut à droite
};

unsigned int vaoID[1]; // VAO
unsigned int vboID[1]; // VBO

namespace Engine
{
	ENGINE_EXP Game::Game()
	{
		inputManager = InputManager::GetInstance();
		inputManager->BindKey<Game>(SDLK_ESCAPE, SDL_EventType::SDL_KEYUP, this, &Game::Quit);
		sceneManager = SceneManager::GetInstance();
	}

	ENGINE_EXP void Game::MainLoop(Window * toRemove) //penser à enlever le parametre
	{
		glViewport(0, 0, 1280, 720);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClearDepth(1.0f);

		Shader vs;																																				//
		vs.LoadShader("C:/Users/Julien Falcioni/Desktop/GitRepo/Engine/x64/Debug/Shaders/vs.txt", Shader::EShaderType::VERTEX_SHADER);							//
		Shader fs;																																				//
		fs.LoadShader("C:/Users/Julien Falcioni/Desktop/GitRepo/Engine/x64/Debug/Shaders/fs.txt", Shader::EShaderType::FRAGMENT_SHADER);						//
																																								//
		Program p = Program();																																	//
																																								//
		p.AttachShader(vs);																																		//
		p.AttachShader(fs);																																		//
		p.LinkProgram();																																		//  a enlever
																																								//
		GLuint uniformID = p.GetUniformLocation("ModelViewProjectionMatrix");																					//
																																								//
		GLuint vertexPositionAttrib = p.GetAttributeLocation("VertexPosition");																					//
		GLuint vertexColorAttrib = p.GetAttributeLocation("VertexColor");																						//
																																								//
		VertexBufferObject vbo = VertexBufferObject(CubeArray, 48, IndiceArray, 36);																			//
		VertexArrayObject vao = VertexArrayObject();																																			//
		vao.Bind();
		//vao.AddVBO(CubeArray, 48, IndiceArray, 36);

		//glVertexAttribPointer(vertexColorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (float *)NULL + (0));
		//glVertexAttribPointer(vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (float *)NULL + (3));
		//vao.Unbind();

		// Et on appelle toutes les fonctions qui modifient l'état des tableaux de sommets

		glEnableVertexAttribArray(vertexPositionAttrib);
		glEnableVertexAttribArray(vertexColorAttrib);

		vbo.Bind();

		// On envoie les données
		glVertexAttribPointer(vertexColorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (float *)NULL + (0));
		glVertexAttribPointer(vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (float *)NULL + (3));

		vao.Unbind();

		glm::mat4 matrix = glm::perspective(glm::radians(60.0f), 16.0f / 9.0f, 0.1f, 100.f) * glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)), 45.0f, glm::vec3(1.0f,1.0f,1.0f));

		while (run)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			inputManager->DoInputs();
			sceneManager->UpdateCurrentScene();

			p.UseProgram();
			
			glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(matrix));
			
			vao.Draw();

			p.StopUseProgram();

			SDL_GL_SwapWindow(toRemove->window);
		}
	}

	ENGINE_EXP void Game::Quit()
	{
		run = false;
	}

	ENGINE_EXP Game::~Game()
	{
	}
}
