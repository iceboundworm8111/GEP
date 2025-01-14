#include "GUI.h"
#include "Core.h"
#include "Texture.h"	
#include "Input.h"
#include "Mouse.h"
#include "Model.h"


namespace ProjectEngine
{

	GUI::GUI(std::shared_ptr<Core> core)
	{
		mCore = core;

		Render::Face face;
		face.a.position = glm::vec3(1.0f, 0.0f, 0.0f);
		face.b.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face.c.position = glm::vec3(0.0f, 0.0f, 0.0f);
		face.a.texcoord = glm::vec2(1.0f, 0.0f);
		face.b.texcoord = glm::vec2(0.0f, 1.0f);
		face.c.texcoord = glm::vec2(0.0f, 0.0f);
		mMesh->add(face);

		Render::Face face2;
		face2.a.position = glm::vec3(1.0f, 0.0f, 0.0f);
		face2.b.position = glm::vec3(1.0f, 1.0f, 0.0f);
		face2.c.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face2.a.texcoord = glm::vec2(1.0f, 0.0f);
		face2.b.texcoord = glm::vec2(1.0f, 1.0f);
		face2.c.texcoord = glm::vec2(0.0f, 1.0f);
		mMesh->add(face2);
	}


	int GUI::Button(glm::vec2 _position, glm::vec2 _size, std::shared_ptr<Texture> _texture)
	{
		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(_position, 0.0f));
		model = glm::scale(model, glm::vec3(_size, 1.0f));
		mShader->uniform("u_Model", model);

		int width = 500;
		int height = 500;

		glm::mat4 guiProjection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
		mShader->uniform("u_Projection", guiProjection);
		mShader->uniform("u_View", glm::mat4(1.0f));
		mShader->draw(mMesh.get(), _texture->mTexture.get());


		glm::ivec2 mousePos = mCore.lock()->GetInput()->GetMouse()->GetPosition();

		mousePos.y = height - mousePos.y;

		if (mousePos.x > _position.x && mousePos.x < _position.x + _size.x &&
			mousePos.y > _position.y && mousePos.y < _position.y + _size.y)
		{
			if (mCore.lock()->GetInput()->GetMouse()->isClickPressed(0))
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
		return 2;
	}
	int GUI::test(std::shared_ptr<Model> _model);
	{
		std::cout << "test" << std::endl;
		return 1;
	}
}
