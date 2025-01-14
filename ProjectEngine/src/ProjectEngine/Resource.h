#pragma once

#include <string>

namespace ProjectEngine
{
	struct Resources;
	struct Resource
	{
		virtual void OnLoad() = 0;
		std::string GetPath() const;
	private:
		friend struct ProjectEngine::Resources;
		std::string mPath;
		void Load();
	};
}