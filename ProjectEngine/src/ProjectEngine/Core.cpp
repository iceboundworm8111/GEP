#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include "Resources.h"	
#include "Input.h"
#include "Audio.h"
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
	/**
	 * @brief Initializes the Core class and all of its components.
	 *
	 * @return std::shared_ptr<Core> A shared pointer to the Core class.
	 */
	std::shared_ptr<Core> Core::Initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->mWindow = std::make_shared<Window>();
		rtn->mResources = std::make_shared<Resources>();
		rtn->mInput = std::make_shared<Input>(); // Keyboard and Mouse is included in Input to make further additions easier down the line such as gamepad
		rtn->mAudio = std::make_shared<Audio>();
		rtn->mSelf = rtn;

		return rtn;
	}

	/**
	 * @brief Initializes the Entity class and all of its components.
	 *
	 * @return std::shared_ptr<Entity> A shared pointer to the Entity class.
	 */
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

	/**
	 * @brief Gets the window associated with the Core.
	 *
	 * @return std::shared_ptr<Window> A shared pointer to the Window class.
	 */
	std::shared_ptr<Window> Core::GetWindow() const
	{
		return mWindow;
	}

	/**
	 * @brief Gets the resources associated with the Core.
	 *
	 * @return std::shared_ptr<Resources> A shared pointer to the Resources class.
	 */
	std::shared_ptr<Resources> Core::GetResources() const
	{
		return mResources;
	}

	/**
	 * @brief Gets the input handler associated with the Core.
	 *
	 * @return std::shared_ptr<Input> A shared pointer to the Input class.
	 */
	std::shared_ptr<Input> Core::GetInput() const
	{
		return mInput;
	}

	/**
	 * @brief Gets the audio handler associated with the Core.
	 *
	 * @return std::shared_ptr<Audio> A shared pointer to the Audio class.
	 */
	std::shared_ptr<Audio> Core::GetAudio() const
	{
		return mAudio;
	}

	/**
	 * @brief The main loop function that handles events and updates entities.
	 *
	 * @param _userData Pointer to user data.
	 * @param mRunning Reference to the running state of the loop.
	 */
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
		SDL_GL_SwapWindow(self->mWindow->mRaw);
	}


	/**
	 * @brief Starts the main loop of the Core.
	 */
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
