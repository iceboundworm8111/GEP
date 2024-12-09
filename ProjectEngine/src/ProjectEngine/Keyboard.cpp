#include "Keyboard.h"

namespace ProjectEngine
{
	void Keyboard::Update()
	{
		mPressedKeys.clear();
		mReleasedKeys.clear();
	}

	bool Keyboard::isKey(int _key)
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
	bool Keyboard::isKeyPressed(int _key)
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
	bool Keyboard::isKeyReleased(int _key)
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
