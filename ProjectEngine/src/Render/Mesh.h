#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
struct Vertex
{
	glm::vec3 position;
	glm::vec2 texcoord;
	glm::vec3 normal;
};

struct Face
{
	Vertex a;
	Vertex b;
	Vertex c;
};

struct Mesh
{
	Mesh();

	void add(const Face& _face);
	GLuint id();
	GLsizei vertex_count() const;

private:
	std::vector<Face> m_faces;
	GLuint m_vaoid;
	GLuint m_vboid;
	bool m_dirty;

};