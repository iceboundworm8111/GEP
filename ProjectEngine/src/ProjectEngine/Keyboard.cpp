#include "Keyboard.h"

namespace ProjectEngine
{
	void Keyboard::Update()
	{
		mPressedKeys.clear();
		mReleasedKeys.clear();
	}

	bool Keyboard::IsKey(int _key)
	{
		for (int i = 0; i < mKeys.size(); i++)
		{
			if (mKeys[i] == _key)
			{
				return true;
			}
		}
		return false;
	}
	bool Keyboard::IsKeyPressed(int _key)
	{
		for (int i = 0; i < mKeys.size(); i++)
		{
			if (mKeys[i] == _key)
			{
				return true;
			}
		}
		return false;
	}
	bool Keyboard::IsKeyReleased(int _key)
	{
		for (int i = 0; i < mKeys.size(); i++)
		{
			if (mKeys[i] == _key)
			{
				return true;
			}
		}
		return false;
	}

}
