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
		

	private:
		friend struct ProjectEngine::Entity;
		
		std::weak_ptr <Entity> mEntity;

		void Tick();
		void Render();
	};
}
