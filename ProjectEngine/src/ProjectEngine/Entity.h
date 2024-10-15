#include <memory>
#include <vector>
namespace ProjectEngine
{
	struct Core;
	struct Component;

	struct Entity
	{
	public:
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->mEntity = mSelf;
			rtn->OnInitialize();

			mComponents.push_back(rtn);

			return rtn;
		}
	private:
		friend struct ProjectEngine::Core;

		std::weak_ptr<Core> mCore;
		std::weak_ptr<Entity> mSelf;
		

		std::vector<std::shared_ptr<Component> > mComponents;
		void OnTick();

	};
}