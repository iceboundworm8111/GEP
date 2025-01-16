#pragma once

#include <glm/glm.hpp>
#include <memory>

namespace ProjectEngine
{
	struct Keyboard;
	struct Transform;
	struct Entity;
	struct GUI;

	/**
	 * @brief The Component struct is a base struct for all components that can be attached to an entity.
	 */
	struct Component
	{
	public:
		/**
		 * @brief Called when the component is initialized.
		 */
		virtual void OnInitialize();

		/**
		 * @brief Called every tick to update the component.
		 */
		virtual void OnTick();

		/**
		 * @brief Called every render cycle to render the component.
		 */
		virtual void OnRender();
		/**
		* @brief Called every render cycle to render the GUI.
		**/ 
		virtual void OnGUI() { }

		/**
		 * @brief Gets the entity to which this component is attached.
		 * @return A shared pointer to the Entity.
		 */
		std::shared_ptr<Entity> GetEntity();

		/**
		 * @brief Gets the keyboard input manager.
		 * @return A shared pointer to the Keyboard.
		 */
		std::shared_ptr<Keyboard> GetKeyboard();

		/**
		 * @brief Gets the transform component of the entity.
		 * @return A shared pointer to the Transform.
		 */
		std::shared_ptr<Transform> GetTransform();

		/**
		 * @brief Gets the position of the entity.
		 * @return The position as a glm::vec3.
		 */
		glm::vec3 GetPosition();

		/**
		 * @brief Sets the position of the entity.p
		 * @param _position The new position as a glm::vec3.
		 */
		void SetPosition(glm::vec3 _position);
		/**
		* @brief Gets the GUI component of the entity.
		* @return A shared pointer to the GUI.
		*/
		std::shared_ptr<GUI> GetGUI();
	private:
		friend struct ProjectEngine::Entity;

		std::weak_ptr<Entity> mEntity; ///< A weak pointer to the entity to which this component is attached.

		/**
		 * @brief Internal tick function called every tick to update the component.
		 */
		void Tick();

		/**
		 * @brief Internal render function called every render cycle to render the component.
		 */
		void Render();
		/**
		 * @brief Internal render function called every render cycle to render the GUI.
		 */
		void GUI();
	};
}