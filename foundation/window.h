#ifndef WINDOW_H
#define WINDOW_H

#include "./object.h"

#include "./maths/vector2.h"
#include "./string/string.h"
#include <GLFW/glfw3.h>

class Window : public Object {
public:
	Vector2 size = Vector2(800.0f, 600.0f);
	Vector2 position = Vector2(0.0f, 0.0f);
	String title = String("Untitled");

	Window();
	Window(Vector2 size, Vector2 position, String title);
	~Window();

	void show();
	void run();
	void setTitle(const String& new_title);

private:
	GLFWwindow* m_glfwWindow = nullptr;
	bool m_working = false;
};

#endif