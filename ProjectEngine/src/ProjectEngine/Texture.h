#pragma once
#include "Resource.h"
#include "Render/Render.h"

#include <memory>

namespace ProjectEngine
{
	struct ModelRenderer;
	struct GUI;
	struct Texture : public Resource
	{

		void OnLoad() {mTexture = std::make_shared<Render::Texture>(GetPath() + ".png"); }

	private:
		friend struct ModelRenderer;
		friend struct GUI;
		std::shared_ptr<Render::Texture> mTexture;
	};


}