#include <vector>

namespace ProjectEngine
{
	struct Mouse
	{

		bool isClick(int _click);
		bool isClickPressed(int _click);
		bool isClickReleased(int _click);

		int GetXPosition() { return mXpos; }
		int GetYPosition() { return mYpos; }

	private:


		friend class Input;
		void Update();
		std::vector <int> mClick;
		std::vector <int> mClickPressed;
		std::vector <int> mClickReleased;

		int mXpos = 0;
		int mYpos = 0;
	};


}