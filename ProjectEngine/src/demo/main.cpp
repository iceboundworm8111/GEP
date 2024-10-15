#include <ProjectEngine/ProjectEngine.h>

#include <iostream>
using namespace ProjectEngine;

struct Player : Component
{
	void OnInitialize()
	{
		std::cout << "OnInitialize Executed" << std::endl;
	}
	void OnTick()
	{

	}
	
};

int main()
{
	std::shared_ptr<Core> core = Core::Initialize();
	std::shared_ptr<Entity> ent = core->AddEntity();

	ent->AddComponent<Player>();

	core->start();

	return 0;
}


