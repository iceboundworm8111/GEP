#include "Mouse.h"

namespace ProjectEngine
{
	void Mouse::Update()
	{
		mClickPressed.clear();
		mClickReleased.clear();
	}
	bool Mouse::isClick(int _click)
	{
		for (int i = 0; i < mClick.size(); i++)
		{
			if (mClick[i] == _click)
			{
				return true;
			}
		}
		return false;
	}
	bool Mouse::isClickPressed(int _click)
	{
		for (int i = 0; i < mClick.size(); i++)
		{
			if (mClick[i] == _click)
			{
				return true;
			}
		}
		return false;
	}
	bool Mouse::isClickReleased(int _click)
	{
		for (int i = 0; i < mClick.size(); i++)
		{
			if (mClick[i] == _click)
			{
				return true;
			}
		}
		return false;
	}
}