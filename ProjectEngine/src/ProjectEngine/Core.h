#include <memory>
#include <vector>

namespace ProjectEngine
{
	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> Initialize();
		void start();
		std::shared_ptr<Entity> AddEntity();

	private:
		int mDummy;
		std::vector<std::shared_ptr<Entity>>mEntities;
		std::weak_ptr<Core> mSelf;
	};
}