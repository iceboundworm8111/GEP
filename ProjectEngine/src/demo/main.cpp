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
		if (GetKeyboard()->IsKeyPressed(SDLK_p))
		{
			std::cout << "p" << std::endl;
			GetEntity()->GetComponent<AudioSource>()->Play();
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
	
	std::shared_ptr<BoxCollider> bc = ent->AddComponent<BoxCollider>();
	bc->SetOffset(glm::vec3(0, 0.2f, 0.54f));
	bc->SetSize(glm::vec3(3.2f, 1.7f, 8.4f));
	ent->AddComponent<Rigidbody>();
	// second
	std::shared_ptr<Entity> ent2 = core->AddEntity();
	ent2->AddComponent<TriangleRenderer>();
	ent2->GetComponent<Transform>()->SetPosition(vec3(-1.0f, 0.0f, -10.0f));


	std::shared_ptr<BoxCollider> bc2 = ent2->AddComponent<BoxCollider>();
	bc2->SetOffset(glm::vec3(0, 0.0f, 0.0f));
	bc2->SetSize(glm::vec3(3.2f, 1.7f, 8.4f));
	std::shared_ptr<AudioSource> entAS = ent->AddComponent<AudioSource>();
	std::shared_ptr<Sound> sound = core->GetResources()->Load<Sound>("sounds/dixie_horn");
	entAS->SetSound(sound);
	if (sound) {
		printf("Audio path assigned correctly\n");
	}
	else {
		printf("Failed to assign audio path\n");
	}
	core->start();

	return 0;
}


