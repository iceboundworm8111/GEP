#include <memory>
#include <vector>
#include <stdexcept>
namespace ProjectEngine
{
	struct Core;
	struct Component;

	struct Entity
	{
		

		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (size_t i = 0; i < mComponents.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(mComponents[i]);
				if (rtn)
				{
					return rtn;
				}
				
			}
			throw std::runtime_error("Component not found");
			return nullptr;
		}


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

		std::shared_ptr<Core> GetCore();

	private:
		friend struct ProjectEngine::Core;

		std::weak_ptr<Core> mCore;
		std::weak_ptr<Entity> mSelf;
		

		std::vector<std::shared_ptr<Component> > mComponents;
		void OnTick();
		void OnRender();

	};
}