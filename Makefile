CXX = clang++
CXXFLAGS = -std=c++17 -Wall \
  -I/opt/homebrew/include

LDFLAGS = -L/opt/homebrew/lib \
  -lglfw -framework OpenGL

SRC = main.cpp \
      foundation/object.cpp \
      foundation/window.cpp \
      foundation/maths/vector2.cpp \
      foundation/string/string.cpp

main: main.cpp
	$(CXX) $(CXXFLAGS) $(SRC) -o main $(LDFLAGS)

clean:
	rm -f main
