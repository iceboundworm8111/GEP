#include "Component.h"
#include <GL/glew.h>

namespace ProjectEngine
{
	struct TriangleRenderer : Component
	{
		~TriangleRenderer();

		void onInititialize();

	private:
		GLuint mPositionsVboId;
		GLuint mVaoId;
		GLuint mShader;
		GLuint mProjLocl;



	};
}