#include "glm/glm.hpp"
#include "Component.h"
namespace ProjectEngine
{
	struct Transform : Component
	{
	public:
		glm::mat4 GetModelMatrix();
		glm::vec3 GetPosition() { return mPosition; }
		void SetPosition(glm::vec3 position) { mPosition = position; }
	private:
		glm::vec3 mPosition{ 0.0f };
		glm::vec3 mRotation{ 0.0f };
		glm::vec3 mScale{ 1.0f };
	};
}