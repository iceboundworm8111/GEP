#pragma once

#include <AL/al.h>
#include <AL/alc.h>


namespace ProjectEngine
{
	struct Audio
	{
		Audio();
		~Audio();
	private:
		ALCcontext* mContext;
		ALCdevice* mDevice;
	};
}