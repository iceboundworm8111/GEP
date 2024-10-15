#include "Component.h"

namespace ProjectEngine
{
	void Component::OnInitialize(){}
	void Component::OnTick(){}
	void Component::Tick()
	{
		OnTick();
	}
}