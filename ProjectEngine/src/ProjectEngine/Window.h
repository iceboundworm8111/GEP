#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

namespace ProjectEngine
{
	struct Window
	{
		Window();
		~Window();
		void OnInitialize(int mWidth, int mHeight);

	private:
		SDL_Window* mRaw;

		SDL_GLContext mContext;

		Window(const Window& _copy);
		Window& operator*(const Window& _assign);
		int mWidth;
		int mHeight;
	};
}