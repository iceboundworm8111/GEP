#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

namespace ProjectEngine
{

	std::shared_ptr<Core> Core::Initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->mWindow = std::make_shared <Window>();
		rtn->mSelf = rtn;

		return rtn;
	}

	std::shared_ptr<Entity> Core::AddEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		mEntities.push_back(rtn);
		rtn->mSelf = rtn;
		rtn->mCore = mSelf;
		std::cout << rtn->mCore.lock().get() << std::endl;

		return rtn;
	}
	std::shared_ptr<Window> Core::GetWindow() const
	{
		return mWindow;
	}

	void Core::start()
	{
		while (true)
		{
			SDL_Event event = { 0 };
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					return;
				}

			}

			for (size_t j = 0; j < mEntities.size(); j++)
			{
				mEntities.at(j)->OnTick();
			}

			glClearColor(1,0,0,1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t j = 0; j < mEntities.size(); j++)
			{
				mEntities.at(j)->OnRender();
			}
			SDL_GL_SwapWindow(mWindow->mRaw);
		}
	}
}
