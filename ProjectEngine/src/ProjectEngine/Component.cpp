#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Input.h"
#include "Keyboard.h"
#include "Transform.h"
#include "GUI.h"

namespace ProjectEngine
{
	void Component::OnInitialize() {}
	void Component::OnTick() {}
	void Component::OnRender() {}

	void Component::Tick()
	{
		OnTick();
	}
	void Component::Render()
	{
		OnRender();
	}
	std::shared_ptr<Entity> Component::GetEntity()
	{
		return mEntity.lock();
	}
	std::shared_ptr<Keyboard> Component::GetKeyboard()
	{
		return GetEntity()->GetCore()->GetInput()->GetKeyboard();
	}
	std::shared_ptr<Transform> Component::GetTransform()
	{
		return GetEntity()->GetComponent<Transform>();
	}
	glm::vec3 Component::GetPosition()
	{
		return GetTransform()->GetPosition();
	}
	void Component::SetPosition(glm::vec3 _position)
	{
		GetTransform()->SetPosition(_position);
	}

	void Component::GUI()
	{
		OnGUI();
	}
	std::shared_ptr<GUI> Component::GetGUI()
	{
		return GetEntity()->GetCore()->GetGUI();
	}
}