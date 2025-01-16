#pragma once

#include <memory>
#include <vector>

namespace ProjectEngine
{
	struct Entity;
	struct Window;
	struct Resources;
	struct Input;
	struct Audio;
	struct GUI;

	/**
	 * @brief The Core struct is responsible for initializing and managing the main components of the engine.
	 */
	struct Core
	{
		/**
		 * @brief Initializes the core engine components.
		 * @return A shared pointer to the Core instance.
		 */
		static std::shared_ptr<Core> Initialize();

		/**
		 * @brief The main loop of the engine.
		 * @param _userData User data to be passed to the loop.
		 * @param _Running A boolean flag to control the running state of the loop.
		 */
		static void loop(void* _userData, bool& _Running);

		/**
		 * @brief Starts the core engine.
		 */
		void start();

		/**
		 * @brief Adds a new entity to the engine.
		 * @return A shared pointer to the newly added Entity.
		 */
		std::shared_ptr<Entity> AddEntity();

		/**
		 * @brief Gets the window associated with the engine.
		 * @return A shared pointer to the Window.
		 */
		std::shared_ptr<Window> GetWindow() const;

		/**
		 * @brief Gets the resources manager associated with the engine.
		 * @return A shared pointer to the Resources.
		 */
		std::shared_ptr<Resources> GetResources() const;

		/**
		 * @brief Gets the GUI manager associated with the engine.
		 * @return A shared pointer to the GUI.
		 */
		std::shared_ptr<GUI> GetGUI() const;

		/**
		 * @brief Gets the input manager associated with the engine.
		 * @return A shared pointer to the Input.
		 */
		std::shared_ptr<Input> GetInput() const;

		/**
		 * @brief Gets the audio manager associated with the engine.
		 * @return A shared pointer to the Audio.
		 */
		std::shared_ptr<Audio> GetAudio() const;

		void Quit() { mRunning = false; }

		/**
		 * @brief Finds components of a specific type in all entities.
		 * @tparam T The type of the components to find.
		 * @param _out A vector to store the found components.
		 */
		template <typename T>
		void FindComponents(std::vector<std::shared_ptr<T>>& _out)
		{
			for (size_t ei = 0; ei < mEntities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = mEntities.at(ei);
				for (size_t ci = 0; ci < e->mComponents.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->mComponents.at(ci);
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

	private:
		std::shared_ptr<Window> mWindow; ///< The window associated with the engine.
		bool mRunning; ///< A flag indicating whether the engine is running.
		std::shared_ptr<Input> mInput; ///< The input manager associated with the engine.
		std::shared_ptr<Audio> mAudio; ///< The audio manager associated with the engine.
		std::shared_ptr<Resources> mResources; ///< The resources manager associated with the engine.
		std::vector<std::shared_ptr<Entity>> mEntities; ///< A list of entities managed by the engine.
		std::weak_ptr<Core> mSelf; ///< A weak pointer to the Core instance.
		std::shared_ptr<GUI> mGUI; ///< The GUI manager associated with the engine.
		
	};
}