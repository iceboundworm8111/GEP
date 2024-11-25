#include "Component.h"

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
}