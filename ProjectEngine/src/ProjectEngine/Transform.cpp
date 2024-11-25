#include "Transform.h"
#include <Render/Render.h>
namespace ProjectEngine
{
	glm::mat4 Transform::GetModelMatrix()
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, mPosition);
		//todo: add rotation
		rtn = glm::scale(rtn, mScale);
		return rtn;
	}
	
}