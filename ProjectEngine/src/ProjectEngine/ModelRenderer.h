#include "Component.h"
#include <Render/Render.h>
namespace ProjectEngine
{
	struct ModelRenderer : Component
	{
		ModelRenderer();
		void OnRender();

	public:

	private:
		Render::Mesh mMesh;
		Render::Model mModel;
		Render::Shader mShader;
		Render::Texture mTexture;
	};

}