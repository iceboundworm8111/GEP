#pragma once

#include "Keyboard.h"
#include "Mouse.h"

#include <SDL2/SDL.h>
#include <memory>

namespace ProjectEngine
{
	struct Core;

	struct Input
	{

		Input();
		void Update();

		std::shared_ptr<Keyboard> GetKeyboard() { return mKeyboard; }

		std::shared_ptr<Mouse> GetMouse() { return mMouse; }
	private:
		friend class Core;

		void CheckInput(const SDL_Event& _event);


		std::shared_ptr<Keyboard> mKeyboard;
		std::shared_ptr<Mouse> mMouse;
	};
}