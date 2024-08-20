#include "Game.h"

Game::Game(unsigned int width, unsigned int height, const string &title)
{
	m_Width = width;
	m_Height = height;
	m_Title = title;
	this->init();
}

Game::~Game()
{
	this->clean();
}

void Game::run()
{
	while (!glfwWindowShouldClose(m_Window) && m_Runing)
	{
		this->processinput(); 
		this->update();
		this->render();
	}
	
}

void Game::init()
{
	//cout << "init" << endl;
	
	if (!glfwInit())
	{
		cout << "Error glfwInit " << endl;
		return;
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	



	/*
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	*/



	m_Window = glfwCreateWindow(m_Width,m_Height,m_Title.c_str(), NULL, NULL);
	if (!m_Window)
	{
		cout << "Error glfwCreateWindow" << endl;
		return;
	}
	glfwMakeContextCurrent(m_Window);//create opengl context
	//cout << glGetString(GL_VERSION) << endl;
	//cout << glGetString(GL_RENDER) << endl;
	//cout << glGetString(GL_VENDOR) << endl;
	//cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;


	m_Runing = true;
	glClearColor(0.0f,1.0f,0.0f,1.0f);


	//glGenVertexArrays(1,&VAO);
	//glBindVertexArrays(VAO);

}

void Game::processinput()
{
	//cout << "processinput" << endl;
}

void Game::update()
{
	//cout << "update" << endl;
}

void Game::render()
{
	//cout << "render" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Game::clean()
{
	//cout << "clean" << endl;
	if(m_Window)
	{
		glfwDestroyWindow(m_Window);
		m_Window = NULL;
	}
	glfwTerminate();
}