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
			GetTransform()->Rotate(vec3(0.0f, 90.0f, 0.0f));
		}
		if (GetKeyboard()->IsKeyPressed(SDLK_d))
		{
			std::cout << "D" << std::endl;
			GetTransform()->Move(vec3(0.01f, 0.0f, 0.0f));
			GetTransform()->Rotate(vec3(0.0f, -90.0f, 0.0f));
		}
		if (GetKeyboard()->IsKeyPressed(SDLK_p))
		{
			std::cout << "p" << std::endl;
			GetEntity()->GetComponent<AudioSource>()->Play();
		}
	}
	void OnGUI()
	{
		
		int i = GetGUI()->Button(glm::vec2(0, 0), glm::vec2(200, 200), GetEntity()->GetCore()->GetResources()->Load<Texture>("textures/Quit"));
		if (i == 1)
		{
			GetEntity()->GetCore()->Quit();
		}

	}
	
};

#undef main
int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	//cruthers
	std::shared_ptr<Entity> Cruthers = core->AddEntity();
	Cruthers->AddComponent<Player>();

	std::shared_ptr<ModelRenderer> MdlRnd = Cruthers->AddComponent<ModelRenderer>();
	MdlRnd->SetModel(core->GetResources()->Load<Model>("models/cat/cat"));
	MdlRnd->SetTexture(core->GetResources()->Load<Texture>("textures/cat"));
	Cruthers->GetComponent<Transform>()->SetPosition(vec3(0.0f, -1.3f, -10.0f));
	Cruthers->GetComponent<Transform>()->SetScale(vec3(-0.5, -0.5, -0.5));
	//cruthers box colider
	std::shared_ptr<BoxCollider> bc = Cruthers->AddComponent<BoxCollider>();
	bc->SetOffset(glm::vec3(0, 0.2f, 0.54f));
	bc->SetSize(glm::vec3(3.2f, 1.7f, 8.4f));
	Cruthers->AddComponent<Rigidbody>();


	//dirt
	std::shared_ptr<Entity> dirt = core->AddEntity();
	std::shared_ptr<ModelRenderer> MdlRnd2 = dirt->AddComponent<ModelRenderer>();
	MdlRnd2->SetModel(core->GetResources()->Load<Model>("models/dirt/dirt"));
	MdlRnd2->SetTexture(core->GetResources()->Load<Texture>("textures/dirt"));
	dirt->GetComponent<Transform>()->SetPosition(vec3(0.0f, -5.0f, -10.0f));
	dirt->GetComponent<Transform>()->SetScale(vec3(5.0f, 1.5f, 1.5f));
	
	//Triangle
	std::shared_ptr<Entity> Triangle = core->AddEntity();
	Triangle->AddComponent<TriangleRenderer>();
	Triangle->GetComponent<Transform>()->SetPosition(vec3(-5.1f, 3.0f, -10.0f));

	//triangle box collider
	std::shared_ptr<BoxCollider> bc2 = Triangle->AddComponent<BoxCollider>();
	bc2->SetOffset(glm::vec3(0, 0.0f, 0.0f));
	bc2->SetSize(glm::vec3(3.2f, 1.7f, 8.4f));


	//audio
	std::shared_ptr<AudioSource> entAS = Cruthers->AddComponent<AudioSource>();
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


