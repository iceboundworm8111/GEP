#include "Window.h"
namespace ProjectEngine
{
	Window::Window()
	{
		mHeight = 1080;
		mWidth = 720;
		OnInitialize(mHeight, mWidth);
	}
	Window ::~Window()
	{
		SDL_GL_DeleteContext(mContext);
		SDL_DestroyWindow(mRaw);
		SDL_Quit();
	}
	void Window::OnInitialize(int width, int height)
	{
		mRaw = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!mRaw)
		{
			throw std::exception();
		}
		mContext = SDL_GL_CreateContext(mRaw);

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		std::cout << "Width: " << width << " ," << "Height: " << height << std::endl;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
	}

}