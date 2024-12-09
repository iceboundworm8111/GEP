#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include "Resources.h"	
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>
#include "Transform.h"
#ifdef _EMSCRIPTEN_
#include <emscripten.h>
#endif // _EMSCRIPTEN_

namespace ProjectEngine
{

	std::shared_ptr<Core> Core::Initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->mWindow = std::make_shared <Window>();

		rtn->mResources = std::make_shared<Resources>();

		rtn->mSelf = rtn;

		//OpenAL stuff
		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		ALCcontext* context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);

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
			loop((void*)this,mRunning);
		}
#endif // _EMSCRIPTEN_

	}
}
