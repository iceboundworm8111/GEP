#pragma once


#include <SDL2/SDL.h>
#include <memory>

namespace ProjectEngine
{
	struct Core;
	struct Keyboard;
	struct Mouse;
	struct Input
	{

		Input();
		void Update();

		std::shared_ptr<Keyboard> GetKeyboard() { return mKeyboard; }

		std::shared_ptr<Mouse> GetMouse() { return mMouse; }
		void Quit() { SDL_Quit(); }
	private:
		friend struct Core;

		void CheckInput(const SDL_Event& _event);


		std::shared_ptr<Keyboard> mKeyboard;
		std::shared_ptr<Mouse> mMouse;
	};
}