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

	}
	void Window::OnInitialize(int width, int height)
	{
		SDL_Window* window = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(window))
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}
		std::cout << "Width: " << width << " ," << "Height: " << height << std::endl;
	}

}