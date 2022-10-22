#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>

#include <stb_image/stb_image.h>

#include <iostream>

#include <utills/FileUtills.h>

// *** callbacks functions *** //

/**
 * @brief called every time the user change the size if the screen and match the viewport to the new size
 *
 * @param window - the window to be resized
 * @param width - the new width
 * @param height - the new height
 */
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

class Game
{
public:
	const int windowWidth = 800;
	const int windowHeight = 600;
	const std::string title = "title";

	GLFWwindow *window;

	int run(void)
	{

		initGLFW();

		window = createWindow(windowWidth, windowHeight, title);

		initGLAD();

		// set the view port
		glViewport(0, 0, windowWidth, windowHeight);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		clean();
		return 0;
	}

	GLFWwindow *createWindow(int width, int height, std::string title)
	{
		GLFWwindow *window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			// TODO: throw an exeption
			return nullptr;
		}
		glfwMakeContextCurrent(window);

		return window;
	}

	// *** init functions *** //

	void initGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void initGLAD()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			// TODO: throw an exeption
		}
	}

	// *** clean functions *** //

	void clean()
	{
		glfwTerminate();
	}
};

int main(void)
{
	Game *game = new Game();
	game->run();
	return 1;
}