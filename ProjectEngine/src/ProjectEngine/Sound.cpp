#include "Sound.h"

#include <vector>
#include <stdexcept>

#include "stb_vorbis.c"

namespace ProjectEngine
{
	void Sound::OnLoad()
	{
		std::vector<unsigned char> buffer;

		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;
		size_t samples = stb_vorbis_decode_filename(GetPath().c_str(),&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + GetPath() + "' for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			mFormat = AL_FORMAT_MONO16;
		}
		else
		{
			mFormat = AL_FORMAT_STEREO16;
		}
		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		buffer.resize(samples * channels * sizeof(short));
		memcpy(&buffer.at(0), output, buffer.size());

		// Record the sample rate required by OpenAL
		mFrequency = sampleRate;

		// Clean up the read data
		free(output);
		alGenBuffers(1, &mBufferId);

		alBufferData(mBufferId, mFormat, &buffer.at(0),
			static_cast<ALsizei>(buffer.size()), mFrequency);
	}
}
