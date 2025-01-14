#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
namespace Render
{
	struct Mesh;
	struct Texture;
	struct Model;
	struct Shader
	{

		Shader(const std::string& _vertpath, const std::string _fragpath);
		GLuint id();
		void uniform(const std::string& _name, const glm::mat4& _value);

		void draw(Mesh& _mesh,Texture& _tex);
		void draw(Model& _model, Texture& _tex);
		void draw(Mesh* _mesh, Texture* _tex);
	private:
		GLuint m_id;

		std::string m_vertsrc;
		std::string m_frgsrc;
		bool m_dirty;

	};
}