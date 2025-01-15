#include "Mouse.h"

namespace ProjectEngine
{
	void Mouse::Update()
	{
		mClickPressed.clear();
		mClickReleased.clear();
	}
	bool Mouse::IsClick(int _click)
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
	bool Mouse::IsClickPressed(int _click)
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
	bool Mouse::IsClickReleased(int _click)
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