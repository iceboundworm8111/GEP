#include <ProjectEngine/ProjectEngine.h>

#include <iostream>
using namespace ProjectEngine;

struct Test : Component
{
	int mTemp;
	
};

int main()
{
	std::cout << "Hello World!" << std::endl;

	std::shared_ptr<Core> core = Core::Initialize();
	std::shared_ptr<Entity> ent = core->AddEntity();

	ent->AddComponent<Test>();

	core->start();

	return 0;
}


