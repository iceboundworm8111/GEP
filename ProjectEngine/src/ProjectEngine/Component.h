#pragma once

#include <memory>


namespace ProjectEngine
{
	struct Keyboard;
	struct Entity;
	struct Component
	{
	public:

		virtual void OnInitialize();
		virtual void OnTick();
		virtual void OnRender();
		std::shared_ptr<Entity> GetEntity();
		std::shared_ptr<Keyboard> GetKeyboard();
	private:
		friend struct ProjectEngine::Entity;
		
		std::weak_ptr <Entity> mEntity;
		
		void Tick();
		void Render();
	};
}
