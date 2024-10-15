namespace ProjectEngine
{
	struct Entity;
	struct Component
	{
		
	private:
		friend struct ProjectEngine::Entity;
		
		std::weak_ptr<Entity> mEntity;
	};
}
