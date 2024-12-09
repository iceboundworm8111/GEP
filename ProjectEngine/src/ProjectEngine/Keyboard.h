#include <vector>

namespace ProjectEngine
{
	struct Keyboard
	{
		bool isKey(int _key);
		bool isKeyPressed(int _key);
		bool isKeyReleased(int _key);


	private:

		friend class Input;
		void Update();


		std::vector <int> mKeys;
		std::vector <int> mPressedKeys;
		std::vector <int> mReleasedKeys;
	};
}