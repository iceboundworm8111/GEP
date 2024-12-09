#include "Input.h"


namespace ProjectEngine
{
	Input::Input()
	{
		mKeyboard = std::make_shared<Keyboard>();
		mMouse = std::make_shared<Mouse>();
	}

	void Input::Update()
	{
		mKeyboard->Update();
		mMouse->Update();
	}

	void Input::CheckInput(const SDL_Event& _event)
	{
		if (_event.type == SDL_KEYDOWN)
		{
			mKeyboard ->mKeys.push_back(_event.key.keysym.sym);
			mKeyboard->mPressedKeys.push_back(_event.key.keysym.sym);
		}
		else if (_event.type == SDL_KEYUP)
		{
			mKeyboard->mKeys.push_back(_event.key.keysym.sym);
			mKeyboard->mReleasedKeys.push_back(_event.key.keysym.sym);
		}
		else if (_event.type == SDL_MOUSEBUTTONDOWN)
		{
			mMouse->mClick.push_back(_event.button.button);

		}
		else if (_event.type == SDL_MOUSEBUTTONUP)
		{

		}
	}
}