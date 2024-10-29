#include <memory>
#include <vector>

namespace ProjectEngine
{
	struct Entity;
	struct Window;

	struct Core
	{
		static std::shared_ptr<Core> Initialize();
		void start();
		std::shared_ptr<Entity> AddEntity();
		std::shared_ptr<Window> GetWindow() const;

	private:
		int mDummy;
		std::shared_ptr<Window> mWindow;
		std::vector<std::shared_ptr<Entity>>mEntities;
		std::weak_ptr<Core> mSelf;
	};
}