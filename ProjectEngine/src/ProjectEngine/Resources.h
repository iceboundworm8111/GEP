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
			for (size_t i = 0; i < mResources.size(); ++i)
			{
				// Return it if found
				if (mResources.at(i)->GetPath() == "../assets/"+ _path)
				{
					return std::dynamic_pointer_cast<T>(mResources.at(i));
				}
			}
			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->mPath = "../assets/" + _path;
			rtn->Load();
			mResources.push_back(rtn);
			return rtn;
		}
	private:
		std::vector<std::shared_ptr<Resource>> mResources;
	};
}