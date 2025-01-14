#include "Entity.h"
#include "Component.h"

namespace ProjectEngine
{
	void Entity::OnTick()
	{
		for (size_t k = 0; k < mComponents.size(); k++)
		{
			mComponents.at(k)->Tick();
		}
	}
	void Entity::OnRender()
	{
		for (size_t ci = 0; ci < mComponents.size(); ci++)
		{
			mComponents.at(ci)->Render();
		}
	}

	void Entity::OnGUI()
	{
		for (size_t ci = 0; ci < mComponents.size(); ++ci)
		{
			mComponents.at(ci)->GUI();
		}
	}

	std::shared_ptr<Core> Entity::GetCore()
	{
		return mCore.lock();
	}
}