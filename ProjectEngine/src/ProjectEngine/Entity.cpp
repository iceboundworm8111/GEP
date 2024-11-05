#include "Entity.h"
#include "Component.h"

namespace ProjectEngine
{
	void Entity::OnTick()
	{
		for (size_t k = 0; k < mComponents.size(); k++)
		{
			mComponents.at(k)->OnTick();
		}
	}
	void Entity::OnRender()
	{
		for (size_t ci = 0; ci < mComponents.size(); ci++)
		{
			mComponents.at(ci)->Render();
		}
	}
}