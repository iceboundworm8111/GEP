#include "Shader.h"
#include "Mesh.h"

#include <exception>
#include <iostream>
#include <fstream>
namespace Render
{
	Shader::Shader(const std::string& _vertpath, const std::string _fragpath)
		:m_id(0)
		, m_vertsrc("")
		, m_frgsrc("")
	{
		std::ifstream vfile(_vertpath);

		if (!vfile.is_open())
		{
			throw std::exception();
		}
		std::string vline;
		while (!vfile.eof())
		{
			std::getline(vfile, vline);
			vline += "\n";
			m_vertsrc += vline;
		}

		std::ifstream ffile(_fragpath);
		if (!ffile.is_open())
		{
			throw std::exception();
		}

		std::string fline;
		while (!ffile.eof())
		{
			std::getline(ffile, fline);
			fline += "\n";
			m_frgsrc += fline;
		}
		std::cout << m_frgsrc << std::endl;
		m_dirty = true;


	}

	GLuint Shader::id()
	{
		if (m_dirty)
		{


			/******************** Vertex Shader ***********************/
			// Create a new vertex shader, attach source code, compile it and check for errors.
			GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
			const GLchar* GLvertsrc = m_vertsrc.c_str();
			glShaderSource(vertexShaderId, 1, &GLvertsrc, NULL);
			glCompileShader(vertexShaderId);
			GLint success = 0;
			glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);



			if (!success)
			{
				throw std::exception();
			}


			/******************** Fragment Shader ***********************/
			// Create a new fragment shader, attach source code, compile it and check for errors.

			GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
			const GLchar* GLfragsrc = m_frgsrc.c_str();
			glShaderSource(fragmentShaderId, 1, &GLfragsrc, NULL);
			glCompileShader(fragmentShaderId);
			glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}
			// Create new shader program and attach our shader objects
			GLuint programId = glCreateProgram();


			glAttachShader(programId, vertexShaderId);
			glAttachShader(programId, fragmentShaderId);


			// Ensure the VAO "position" attribute stream gets set as the first position
			// during the link.
			//glBindAttribLocation(programId, 0, "in_Position");

			glBindAttribLocation(programId, 0, "a_Position");
			glBindAttribLocation(programId, 1, "a_TexCoord");
			glBindAttribLocation(programId, 2, "a_Normal");


			// Perform the link and check for failure
			glLinkProgram(programId);
			glGetProgramiv(programId, GL_LINK_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}


			// Bind the shader to change the uniform, set the uniform and reset state
			glUseProgram(programId);

			glUseProgram(0);


			// Detach and destroy the shader objects. These are no longer needed
			// because we now have a complete shader program.
			glDetachShader(programId, vertexShaderId);
			glDeleteShader(vertexShaderId);
			glDetachShader(programId, fragmentShaderId);
			glDeleteShader(fragmentShaderId);


			// Instruct OpenGL to use our shader program and our VAO
			glUseProgram(programId);
			m_id = programId;
			m_dirty = false;
		}
		return m_id;
	}
	void Shader::uniform(const std::string& _name, const glm::mat4& _value)
	{
		GLuint loc = glGetUniformLocation(id(), _name.c_str());

		glUseProgram(id());
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(_value));
		glUseProgram(0);
	}
	void Shader::draw(Mesh& _mesh)
	{
		glUseProgram(id());
		glBindVertexArray(_mesh.id());
		// TODO: Get 3 from mesh size
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(0);
	}
}
