#pragma once

#include "Component.h"
#include "Sound.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <vector>
#include <string>

namespace ProjectEngine
{
	struct AudioSource : public Component
	{
		AudioSource();
		~AudioSource();

		void SetSound(std::shared_ptr<Sound> _sound) { mSound = _sound; alSourcei(mSourceId, AL_BUFFER, mSound->mBufferId); }

		bool IsPlaying();
		void OnTick();
		void Play();

	private:

		std::shared_ptr<Sound> mSound = nullptr;
		ALenum mFormat = 0;
		ALsizei mFrequency = 0;

		ALuint mBufferId = 0;
		ALuint mSourceId;

		bool mLooping = false;
	};

}