#pragma once
#include "Component.h"
namespace ProjectEngine
{
	struct Rigidbody : public Component
	{
		void OnTick();
	};
}