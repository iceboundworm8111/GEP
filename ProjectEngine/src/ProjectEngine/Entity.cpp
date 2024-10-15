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
}