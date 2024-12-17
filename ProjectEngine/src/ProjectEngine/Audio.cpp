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
	}
}