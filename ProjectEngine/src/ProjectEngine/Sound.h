#pragma once

#include "Resource.h"

#include <AL/al.h>

namespace ProjectEngine
{
	class AudioSource;

	struct Sound : public Resource
	{
		void OnLoad();

	private:
		friend class AudioSource;

		ALuint mBufferId = 0;
		ALenum mFormat = 0;
		ALsizei mFrequency = 0;
	};
}