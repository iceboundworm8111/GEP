#pragma once

#include <memory>


namespace ProjectEngine
{
	struct Entity;
	struct Component
	{
	public:

		virtual void OnInitialize();
		virtual void OnTick();
		virtual void OnRender();
		std::shared_ptr<Entity> GetEntity();
	private:
		friend struct ProjectEngine::Entity;
		
		std::weak_ptr <Entity> mEntity;

		void Tick();
		void Render();
	};
}
