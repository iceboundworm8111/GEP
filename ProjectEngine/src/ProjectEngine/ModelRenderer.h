#include "Component.h"
#include <Render/Render.h>
namespace ProjectEngine
{

	struct Model;
	struct Texture;
	struct Shader;
	struct ModelRenderer : Component
	{
		ModelRenderer();

		void OnInitialize();
		void OnRender();
		void SetModel(std::shared_ptr<Model> _model) { mModel = _model; }
		void SetTexture(std::shared_ptr<Texture> _texture) { mTexture = _texture;}


	private:
		Render::Mesh mMesh;
		std::shared_ptr<Model> mModel = nullptr;
		std::shared_ptr<Texture> mTexture = nullptr;
		std::shared_ptr<Shader> mShader = nullptr;
	};

}