#include "./window.h"
#include <iostream>

Window::Window() {}

Window::Window(Vector2 size, Vector2 position, String title) : 
	Object(),
	size(size),
	position(position),
	title(title) {}

Window::~Window() {
	if(m_glfwWindow) glfwDestroyWindow(m_glfwWindow);
    glfwTerminate();
}

void Window::show() {
	m_working = true;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // macOS fix
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_glfwWindow = glfwCreateWindow(size.x, size.y, title.str(), nullptr, nullptr);
	if (!m_glfwWindow) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_glfwWindow);

    while (!glfwWindowShouldClose(m_glfwWindow)) {
        // Render here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_glfwWindow);
        glfwPollEvents();
    }

    m_working = false;
}

void Window::run() {
	while (!glfwWindowShouldClose(m_glfwWindow)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_glfwWindow);
		glfwPollEvents();
    }
}

void Window::setTitle(const String& new_title) {
	title = String(new_title);
	
	if (m_working) {
		std::cout << "Called setTitle on a working window with id " << id() << " May not set properly." << std::endl;
	}

	if (m_glfwWindow) {
		glfwSetWindowTitle(m_glfwWindow, new_title.str());
	}
}
