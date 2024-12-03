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

	std::shared_ptr<ModelRenderer> ent2 = ent->AddComponent<ModelRenderer>();
	ent->AddComponent<Transform>();
	ent->AddComponent<Player>();

	ent->AddComponent<TriangleRenderer>();
	ent->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));

	ent2->SetModel(core->GetResources()->Load<Model>("assets/models/cat"));
	ent2->SetTexture(core->GetResources()->Load<Texture>("assets/textures/cat"));
	ent->AddComponent<ModelRenderer>();
	ent->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -09.0f));
	core->start();

	return 0;
}


