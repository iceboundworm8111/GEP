#include <vector>
#include <glm/glm.hpp>

namespace ProjectEngine
{
	struct Mouse
	{

		bool IsClick(int _click);
		bool IsClickPressed(int _click);
		bool IsClickReleased(int _click);

		int GetXPosition() { return mXpos; }
		int GetYPosition() { return mYpos; }


		glm::ivec2 GetPosition() { return glm::vec2(mXpos, mYpos); }

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