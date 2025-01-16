#pragma once
#include "Resource.h"
#include "Render/Model.h"

#include <memory>

namespace ProjectEngine
{
	struct ModelRenderer;

	struct Model : public Resource
	{
	public:

		void OnLoad() { mModel = std::make_shared<Render::Model>(GetPath() + ".obj"); };

	private:
		friend struct ModelRenderer;
		std::shared_ptr<Render::Model> mModel;
	};
}