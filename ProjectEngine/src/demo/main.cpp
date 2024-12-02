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
	ent->AddComponent<Transform>();
	ent->AddComponent<Player>();

	ent->AddComponent<TriangleRenderer>();
	ent->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));

	core->GetResources()->Load<Model>("assets/models/cat");
	//ent->AddComponent<ModelRenderer>();
	//ent->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -09.0f));
	core->start();

	return 0;
}


