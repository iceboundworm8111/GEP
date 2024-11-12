#include "Texture.h"

#include <stb_image.h>
#include <iostream>
#include <exception>
namespace Render
{
	Texture::Texture(const std::string& _path)
		: m_id(0)
		, m_width(0)
		, m_height(0)
		, m_dirty(false)
	{
		unsigned char* data = stbi_load(_path.c_str(), &m_width, &m_height, NULL, 4);

		if (!data)
		{
			throw std::exception();
		}

		for (size_t i = 0; i < m_width * m_height * 4; ++i)
		{
			m_data.push_back(data[i]);
		}

		free(data);
		m_dirty = true;
	}

	Texture::~Texture()
	{
		if (m_id)
		{
			glDeleteTextures(1, &m_id);
		}
	}

	GLuint Texture::id()
	{
		if (!m_id)
		{
			glGenTextures(1, &m_id);

			if (!m_id)
			{
				throw std::exception();
			}
		}

		if (m_dirty)
		{
			glBindTexture(GL_TEXTURE_2D, m_id);
			//upload image data to the bound texture unit in the GPU
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, &m_data.at(0));
			//generated mipmap so the texture is able to be mappe
			glGenerateMipmap(GL_TEXTURE_2D);

			//unbind at the end
			glBindTexture(GL_TEXTURE_2D, 0);
			m_dirty = false;
		}

		return m_id;
	}
}