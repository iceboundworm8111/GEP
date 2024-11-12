#include <vector>

namespace ProjectEngine
{
	struct Keyboard
	{


	public:
		bool isKey(int _key) { return false; };
		bool isKeyPressed(int _key) { return false; };
		bool isKeyReleased(int _key) { return false; };


	private:

		std::vector <int> mKeys;
		std::vector <int> mPressedKeys;
		std::vector <int> mReleasedKeys;
	};
}