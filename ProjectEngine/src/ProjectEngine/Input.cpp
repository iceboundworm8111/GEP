
#include "Input.h"
#include "Keyboard.h"
#include "Mouse.h"

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
			//mKeyboard->mKeys.push_back(_event.key.keysym.sym);
			for (size_t i = 0; i < mKeyboard->mKeys.size(); i++)
			{
				if (mKeyboard->mKeys.at(i) == _event.key.keysym.sym)
				{
					mKeyboard->mKeys.erase(mKeyboard->mKeys.begin() + i);
					i--;
				}
			}
			mKeyboard->mReleasedKeys.push_back(_event.key.keysym.sym);
		}
		else if (_event.type == SDL_MOUSEBUTTONDOWN)
		{
			mMouse->mClick.push_back(_event.button.button);
			mMouse->mClickPressed.push_back(_event.button.button);
		}
		else if (_event.type == SDL_MOUSEBUTTONUP)
		{
			mMouse->mClick.push_back(_event.button.button);
			mMouse->mClickReleased.push_back(_event.button.button);
		}

		else if (_event.type == SDL_MOUSEMOTION)
		{
			mMouse->mXpos = _event.motion.x;
			mMouse->mYpos = _event.motion.y;
		}
	}
}