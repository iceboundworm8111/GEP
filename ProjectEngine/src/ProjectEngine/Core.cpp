#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include "Resources.h"	
#include "Input.h"
#include "Audio.h"
#include <iostream>
#include "Transform.h"
#include "GUI.h"
#ifdef _EMSCRIPTEN_
#include <emscripten.h>
#endif // _EMSCRIPTEN_

namespace ProjectEngine
{
	
	std::shared_ptr<Core> Core::Initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->mWindow = std::make_shared<Window>();
		rtn->mResources = std::make_shared<Resources>();
		rtn->mInput = std::make_shared<Input>(); // Keyboard and Mouse is included in Input to make further additions easier down the line such as gamepad
		rtn->mAudio = std::make_shared<Audio>();
		rtn->mGUI = std::make_shared<GUI>(rtn);
		rtn->mSelf = rtn;

		return rtn;
	}

	
	std::shared_ptr<Entity> Core::AddEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->mSelf = rtn;
		rtn->mCore = mSelf;
		mEntities.push_back(rtn);
		std::cout << rtn->mCore.lock().get() << std::endl;

		rtn->AddComponent<Transform>();

		return rtn;
	}

	
	std::shared_ptr<Window> Core::GetWindow() const
	{
		return mWindow;
	}

	
	std::shared_ptr<Resources> Core::GetResources() const
	{
		return mResources;
	}

	
	std::shared_ptr<Input> Core::GetInput() const
	{
		return mInput;
	}

	
	std::shared_ptr<Audio> Core::GetAudio() const
	{
		return mAudio;
	}


	std::shared_ptr<GUI> Core::GetGUI() const
	{
		return mGUI;
	}



	void Core::loop(void* _userData, bool& mRunning)
	{
		Core* self = (Core*)_userData;
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				mRunning = false;
				return;
			}
			else
			{
				self->mInput->CheckInput(event);
			}

		}

		for (size_t j = 0; j < self->mEntities.size(); j++)
		{
			self->mEntities.at(j)->OnTick();
		}

		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (size_t j = 0; j < self->mEntities.size(); j++)
		{
			self->mEntities.at(j)->OnRender();
		}

		for (size_t j= 0; j < self->mEntities.size(); j++)
		{
			self->mEntities.at(j)->OnGUI();
		}	
		SDL_GL_SwapWindow(self->mWindow->mRaw);
	}


	
	void Core::start()
	{
		mRunning = true;

#ifdef _EMSCRIPTEN_
		emscripten_set_main_loop_arg(loop, (void*)this, 60, 1);
#else
		while (mRunning)
		{
			loop((void*)this, mRunning);
		}
#endif // _EMSCRIPTEN_

	}
}
