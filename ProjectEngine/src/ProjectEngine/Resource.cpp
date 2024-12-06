#include "Resource.h"

namespace ProjectEngine
{

	void Resource::Load()
	{
		OnLoad();
	}

	std::string Resource::GetPath() const
	{
		return m_path;
	}

}