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
		if (GetKeyboard()->IsKeyPressed(SDLK_a))
		{
			std::cout << "A" << std::endl;
			GetTransform()->Move(vec3(-0.01f, 0.0f, 0.0f));
		}

	}
	
};

#undef main
int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	// first
	std::shared_ptr<Entity> ent = core->AddEntity();
	ent->AddComponent<Player>();

	std::shared_ptr<ModelRenderer> mr = ent->AddComponent<ModelRenderer>();
	mr->SetModel(core->GetResources()->Load<Model>("models/cat/cat"));
	mr->SetTexture(core->GetResources()->Load<Texture>("textures/cat"));
	ent->GetComponent<Transform>()->SetPosition(vec3(1.0f, 0.0f, -10.0f));

	// second
	std::shared_ptr<Entity> ent2 = core->AddEntity();
	ent2->AddComponent<TriangleRenderer>();
	ent2->GetComponent<Transform>()->SetPosition(vec3(-1.0f, 0.0f, -10.0f));



	core->start();

	return 0;
}


