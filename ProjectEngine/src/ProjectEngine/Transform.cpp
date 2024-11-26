#include "Transform.h"
#include <Render/Render.h>
namespace ProjectEngine
{
	glm::mat4 Transform::GetModelMatrix()
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, mPosition);
		rtn = glm::rotate(rtn, glm::radians(mRotation.x), glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, glm::radians(mRotation.y), glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, glm::radians(mRotation.z), glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, mScale);
		return rtn;
	}
	
}