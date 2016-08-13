#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"

int main(int argc, char* argv[])
{
	Display display(1280, 720, "Hello World!");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
			      Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
			      Vertex(glm::vec3(0.5, -0.5, 0),  glm::vec2(1.0, 0.0)), };

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Transform transform;

	float counter = 0.0f;

	while(!display.IsClosed())
	{
		display.Clear(0.0f, 0.0f, 0.0f, 0.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinCounter;
		transform.GetRot().z = counter; // cosf(counter * 50);
		transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform);
		mesh.Draw();

		display.Update();
		counter += 0.01f;
	}

	return 0;
}
