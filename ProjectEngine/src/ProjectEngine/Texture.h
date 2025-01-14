#pragma once
#include "Resource.h"
#include "Render/Render.h"

#include <memory>

namespace ProjectEngine
{
	class ModelRenderer;
	class GUI;
	class Texture : public Resource
	{

		void OnLoad() {
			mTexture = std::make_shared<Render::Texture>(GetPath() + ".png"); 
		}

	private:
		friend class ModelRenderer;
		friend class GUI;
		std::shared_ptr<Render::Texture> mTexture;
	};


}