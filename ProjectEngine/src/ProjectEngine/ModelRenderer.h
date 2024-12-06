#include "Component.h"
#include <Render/Render.h>
namespace ProjectEngine
{

	class Model;
	class Texture;
	class Shader;
	struct ModelRenderer : Component
	{
		ModelRenderer();

		void OnInitialize();
		void OnRender();
		void SetModel(std::shared_ptr<Model> _model) { mModel = _model; }
		void SetTexture(std::shared_ptr<Texture> _texture) { 
			mTexture = _texture;
		}


	private:
		Render::Mesh mMesh;
		//Render::Model mModel;
		//Render::Shader mShader;
		//Render::Texture mTexture;
		std::shared_ptr<Model> mModel = nullptr;
		std::shared_ptr<Texture> mTexture = nullptr;
		std::shared_ptr<Shader> mShader = nullptr;
	};

}