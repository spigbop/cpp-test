
#include <iostream>

#include "foundation/window.h"
#include "foundation/maths/vector2.h"

int main() {
	if (!glfwInit()) return -1;

	Vector2 base(300, 300);
	Vector2 add(100, 100);
	Vector2 sum = base + add;

	Window* win = new Window(sum, {0, 0}, String("ID: ?"));
	win->run();

	delete win;
	win = nullptr;
    return 0;
}
