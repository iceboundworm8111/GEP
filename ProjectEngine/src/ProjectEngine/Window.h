#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

namespace ProjectEngine
{
	class Core;
	struct Window
	{
		Window();
		~Window();
		void OnInitialize(int _width, int _height);

	private:
		friend class ProjectEngine::Core;
		SDL_Window* mRaw;
		SDL_GLContext mContext;

		Window(const Window& _copy);

		int mWidth;
		int mHeight;
	};
}