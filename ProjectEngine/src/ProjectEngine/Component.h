#include <memory>


namespace ProjectEngine
{
	struct Entity;
	struct Component
	{
		void OnInitialize();
		void OnTick();

	private:
		friend struct ProjectEngine::Entity;
		
		std::weak_ptr <Entity> mEntity;

		void Tick();
	};
}
