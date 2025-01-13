#pragma once

#include <glm/glm.hpp>
#include <memory>


namespace ProjectEngine
{
	struct Keyboard;
	struct Transform;
	struct Entity;
	struct Component
	{
	public:

		virtual void OnInitialize();
		virtual void OnTick();
		virtual void OnRender();
		std::shared_ptr<Entity> GetEntity();
		std::shared_ptr<Keyboard> GetKeyboard();
		std::shared_ptr<Transform> GetTransform();
		glm::vec3 GetPosition();
		void SetPosition(glm::vec3 _position);
	private:
		friend struct ProjectEngine::Entity;
		
		std::weak_ptr <Entity> mEntity;
		
		void Tick();
		void Render();
	};
}
