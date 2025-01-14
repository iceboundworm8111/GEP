#include "Component.h"
#include <Render/Render.h>
namespace ProjectEngine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void OnRender();
		
	public:		
		
	private:
		Render::Mesh mMesh;
		Render::Model mModel;
		Render::Shader mShader;
		Render::Texture mTexture;
	};
	
}