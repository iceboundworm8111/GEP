#include "Audio.h"
#include <stdexcept>




namespace ProjectEngine
{
	Audio::Audio()
	{
		mDevice = alcOpenDevice(0);

		if (!mDevice)
		{
			throw std::runtime_error("Unable to open device");
		}

		mContext = alcCreateContext(mDevice, 0);

		if (!mContext)
		{
			throw std::runtime_error("Unable to create context");
		}

		if (!alcMakeContextCurrent(mContext))
		{
			alcDestroyContext(mContext);
			alcCloseDevice(mDevice);
			throw std::runtime_error("unable to make context current");
		}
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	}
	Audio::~Audio()
	{
		alcMakeContextCurrent(NULL);
		alcDestroyContext(mContext);
		alcCloseDevice(mDevice);
	}
}