#pragma once

#include "Render/Render.h"

#include <memory>
#include <iostream>
namespace ProjectEngine
{
	struct Texture;
	struct Core;
	struct Model;
	struct GUI
	{

		GUI(std::shared_ptr<Core> core);
		~GUI() {}

		int Button(glm::vec2 _position, glm::vec2 _size, std::shared_ptr<Texture> _texture);
		int test(std::shared_ptr<Model> _model);
	private:
		std::shared_ptr<Render::Shader> mShader = std::make_shared<Render::Shader>("../assets/shaders/GUIShader.vert", "../assets/shaders/GUIShader.frag");
		std::shared_ptr<Render::Mesh> mMesh = std::make_shared<Render::Mesh>();

		std::weak_ptr<Core> mCore;
	};
}
