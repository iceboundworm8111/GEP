#include <string>

namespace ProjectEngine
{
	struct Resource
	{
		virtual void OnLoad() = 0;
		std::string getPath() const;
	private:
		std::string m_path;
		void load();
	};}