#include <vector>

namespace ProjectEngine
{
	struct Keyboard
	{
		bool IsKey(int _key);
		bool IsKeyPressed(int _key);
		bool IsKeyReleased(int _key);


	private:

		friend class Input;
		void Update();


		std::vector <int> mKeys;
		std::vector <int> mPressedKeys;
		std::vector <int> mReleasedKeys;
	};
}