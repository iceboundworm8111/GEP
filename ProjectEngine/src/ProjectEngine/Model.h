#pragma once
#include "Resource.h"
#include "Render/Model.h"

#include <memory>

namespace ProjectEngine
{
	class ModelRenderer;

	class Model : public Resource
	{
	public:

		void OnLoad() { mModel = std::make_shared<Render::Model>(getPath() + ".obj"); };

	private:
		friend class ModelRenderer;
		std::shared_ptr<Render::Model> mModel;
	};
}