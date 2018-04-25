//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

#include <iostream>
#include "Application.h"
#include "Renderer.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 200;

using namespace std;

int main() {
  Application app(SCR_WIDTH, SCR_HEIGHT);
  app.init();
  app.run();

  return 0;
}
