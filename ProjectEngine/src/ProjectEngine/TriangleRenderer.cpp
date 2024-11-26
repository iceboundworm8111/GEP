#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include <stb_image.h>
namespace ProjectEngine
{


	TriangleRenderer::TriangleRenderer()
		: mModel("../assets/models/hand/hand.obj")
		, mShader("../assets/shaders/simple.vert","../assets/shaders/simple.frag")
	{
		Render::Face face;
		face.a.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face.b.position = glm::vec3(-1.0f, -1.0f, 0.0f);
		face.c.position = glm::vec3(1.0f, -1.0f, 0.0f);
		face.a.texcoord = glm::vec2(0.5f,-1.0f);
		face.b.texcoord = glm::vec2(0.0f, 0.0f);
		face.c.texcoord = glm::vec2(1.0f, 0.0f);

		mMesh.add(face);
	}
	void TriangleRenderer::OnRender()
	{
		int width = 0;
		int height = 0;
		//Loading an image from the hard drive
		unsigned char* image = stbi_load("../assets/textures/image.png", &width, &height, NULL, 4);
		if (!image)
		{
			std::cout << "Failed to load image" << std::endl;
		}
		else
		{
			std::cout << "Loaded image" << std::endl;
		}
		//Generating a texture on the GPU
		GLuint textureId=0;
		glGenTextures(1, &textureId);
		if (!textureId)
		{
			std::cout << "Failed to generate texture" << std::endl;
		}
		else
		{
			std::cout << "Generated texture" << std::endl;
		}

		//Uploading the texture to the GPU
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		free(image);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		

		
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)1080/ (float)720, 0.1f, 100.0f);
		mShader.uniform("u_Projection", projection);
		//Setting the view matrix
		glm::mat4 view(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0, 1, 0));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(1, 0, 0));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0, 0, 1));
		view = glm::inverse(view);
		//mShader.uniform("u_View", view);
		mShader.uniform("u_View", glm::mat4(1.0f));


		//Setting the model matrix
		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = GetEntity()->GetComponent<Transform>()->GetModelMatrix();
		

		mShader.uniform("u_Model", modelMatrix);
		mShader.draw(mMesh);


	
	}


}