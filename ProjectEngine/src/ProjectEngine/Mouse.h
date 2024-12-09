#include <vector>

namespace ProjectEngine
{
	struct Mouse
	{

		////bool isClick(int _click);
		//bool isClickDown(int _click);
		//bool isClickUp(int _click);

		int GetXPosition() { return mXpos; }
		int GetYPosition() { return mYpos; }

	private:


		friend class Input;
		void Update();
		std::vector <int> mClick;

		int mXpos = 0;
		int mYpos = 0;
	};


}