#pragma once

#include "Resource.h"
#include "Render/Shader.h"

#include <memory>

namespace ProjectEngine
{
	class ModelRenderer;

	class Shader : public Resource
	{
		void OnLoad() 
		{
			mShader = std::make_shared<Render::Shader>(GetPath() + ".vert", GetPath() + ".frag");
		}

	private:
		friend class ModelRenderer;
		std::shared_ptr<Render::Shader> mShader;
	};
}