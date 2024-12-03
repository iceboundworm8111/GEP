#include <memory>
#include <vector>

namespace ProjectEngine
{
	struct Entity;
	struct Window;
	struct Resources;

	struct Core
	{

		static std::shared_ptr<Core> Initialize();
		static void loop(void* _userData);
		void start();
		std::shared_ptr<Entity> AddEntity();
		std::shared_ptr<Window> GetWindow() const;
		std::shared_ptr<Resources> GetResources() const;
	private:
		int mDummy;
		std::shared_ptr<Window> mWindow;
		bool mRunning;
		//std::shared_ptr<Input> mInput;
		//std::shared_ptr<Audio> mAudio;
		std::shared_ptr<Resources> mResources;

		std::vector<std::shared_ptr<Entity>>mEntities;
		std::weak_ptr<Core> mSelf;
	};
}