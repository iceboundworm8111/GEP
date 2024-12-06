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

	// first
	std::shared_ptr<Entity> ent = core->AddEntity();
	ent->AddComponent<Player>();

	std::shared_ptr<ModelRenderer> mr = ent->AddComponent<ModelRenderer>();
	mr->SetModel(core->GetResources()->Load<Model>("models/cat/cat"));
	mr->SetTexture(core->GetResources()->Load<Texture>("textures/cat"));
	ent->GetComponent<Transform>()->SetPosition(glm::vec3(1.0f, 0.0f, -10.0f));

	// second
	std::shared_ptr<Entity> ent2 = core->AddEntity();
	ent2->AddComponent<TriangleRenderer>();
	ent2->GetComponent<Transform>()->SetPosition(glm::vec3(-1.0f, 0.0f, -10.0f));

	core->start();

	return 0;
}


