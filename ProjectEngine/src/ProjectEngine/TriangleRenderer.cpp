#include "TriangleRenderer.h"

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
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)1080/ (float)720, 0.1f, 100.0f);
		mShader.uniform("u_Projection", projection);

		glm::mat4 view(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0, 1, 0));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(1, 0, 0));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0, 0, 1));
		view = glm::inverse(view);
		//mShader.uniform("u_View", view);
		mShader.uniform("u_View", glm::mat4(1.0f));


		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -10.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(0, 1, 0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(1, 0, 0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(0, 0, 1));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
		mShader.uniform("u_Model", modelMatrix);

		mShader.draw(mMesh);


	
	}


}