#include <memory>
#include <string>
#include <vector>
#include "Resource.h"

namespace ProjectEngine
{

	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> Load(const std::string& _path)
		{
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				// Return it if found
				if (m_resources.at(i)->GetPath() == _path)
				{
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = "../assets/" + _path;
			rtn->Load();
			m_resources.push_back(rtn);
			return rtn;
		}
	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};
}