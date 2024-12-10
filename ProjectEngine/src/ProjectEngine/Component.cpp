#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Input.h"
#include "Keyboard.h"

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
}