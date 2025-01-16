#include <memory>
#include <vector>
#include <stdexcept>

namespace ProjectEngine
{
	struct Core;
	struct Component;

	/**
	 * @brief The Entity struct represents an entity in the engine, which can have multiple components.
	 */
	struct Entity
	{
		/**
		 * @brief Retrieves a component of the specified type from the entity.
		 * @tparam T The type of the component to retrieve.
		 * @return A shared pointer to the component.
		 * @throws std::runtime_error if the component is not found.
		 */
		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (size_t i = 0; i < mComponents.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(mComponents[i]);
				if (rtn)
				{
					return rtn;
				}
			}
			throw std::runtime_error("Component not found");
			return nullptr;
		}
		/**
		 * @brief Adds a new component of the specified type to the entity.
		 * @tparam T The type of the component to add.
		 * @return A shared pointer to the newly added component.
		 */
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->mEntity = mSelf;
			rtn->OnInitialize();

			mComponents.push_back(rtn);

			return rtn;
		}

		/**
		 * @brief Gets the core engine associated with the entity.
		 * @return A shared pointer to the Core.
		 */
		std::shared_ptr<Core> GetCore();

	private:
		friend struct ProjectEngine::Core;

		std::weak_ptr<Core> mCore; ///< A weak pointer to the core engine.
		std::weak_ptr<Entity> mSelf; ///< A weak pointer to the entity itself.

		std::vector<std::shared_ptr<Component>> mComponents; ///< A list of components attached to the entity.

		/**
		 * @brief Called every tick to update the entity.
		 */
		void OnTick();

		/**
		 * @brief Called every render cycle to render the entity.
		 */
		void OnRender();
		/**
		 * @brief Called every render cycle to render the GUI.
		 */
		void OnGUI();
	};
}