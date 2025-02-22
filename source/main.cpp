#include "Components/Position.h"
#include "Events/EventManager.h"
#include "Program.h"
#include "Systems/SystemManager.h"
#include "common.h"
#include <iostream>
#include <unistd.h>
static void cursorPositionCallback(GLFWwindow *window, double xpos,
                                   double ypos);
static void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                        int mods);
// This function will be used to log errors thrown by GLFW
void glfw_error_callback(int error, const char *description) {
  std::cerr << "GLFW Error: " << error << ": " << description << std::endl;
}
static void mouseClickCallback(GLFWwindow *window, int button, int action, int mods);

EventManager eventManager;
EntityManager entityManager;
SystemManager systemManager(&eventManager, &entityManager);

static GLFWwindow *init() {
  // Set the function to call when an error occurs.
  glfwSetErrorCallback(glfw_error_callback);

  // Initialize GLFW and exit if it failed
  if (!glfwInit()) {
    std::cerr << "Failed to Initialize GLFW" << std::endl;
    return nullptr;
  }
  // ah
  // Request that OpenGL is 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // Only enable core functionalities (disable features from older OpenGL
  // versions that were removed in 3.3)
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Enable forward compatibility with newer OpenGL versions by removing
  // deprecated functionalities This is necessary for some platforms
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Make window size fixed (User can't resize it)
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  // Set Number of sample used in MSAA (0 = Disabled)
  glfwWindowHint(GLFW_SAMPLES, 0);

  // Enable Double Buffering
  glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

  // Set the bit-depths of the frame buffer
  glfwWindowHint(GLFW_RED_BITS, 8);
  glfwWindowHint(GLFW_GREEN_BITS, 8);
  glfwWindowHint(GLFW_BLUE_BITS, 8);
  glfwWindowHint(GLFW_ALPHA_BITS, 8);

  // Set Bits for Depth Buffer
  glfwWindowHint(GLFW_DEPTH_BITS, 24);

  // Set Bits for Stencil Buffer
  glfwWindowHint(GLFW_STENCIL_BITS, 8);

  // Set the refresh rate of the window (GLFW_DONT_CARE = Run as fast as
  // possible)
  glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Phase 1",
                                        nullptr, nullptr);

  glfwMakeContextCurrent(window);

  gladLoadGL(glfwGetProcAddress);

  return window;
}

int main() {

  GLFWwindow *window = init();
  if (window == nullptr) {
    return -1;
  }
  // Game Loop

  Entity *shapes = entityManager.createEntity();
  Position *position = new Position();

  shapes->addComponent(position, typeid(position).name());

  glfwSetCursorPosCallback(window, cursorPositionCallback);
  glfwSetKeyCallback(window, keyCallback);
  glfwSetMouseButtonCallback(window, mouseClickCallback);

  glfwSwapBuffers(window);

  Program prog;

  systemManager.init();
  glfwSwapBuffers(window);

  double startTime;
  double endTime = getTime();

  while (!glfwWindowShouldClose(window)) {
    startTime = getTime();
    double delta = startTime - endTime;
    prog.draw(eventManager.mousePosition);
    glfwSwapBuffers(window);
    glfwPollEvents();
    systemManager.update(delta);

    endTime = getTime();
  }

  return 0;
}

static void cursorPositionCallback(GLFWwindow *window, double xpos,
                                   double ypos) {
  eventManager.mousePosition.x = xpos;
  eventManager.mousePosition.y = ypos;
  eventManager.mouseEvent.trigger(eventManager.mousePosition, entityManager);
}
static void mouseClickCallback(GLFWwindow *window, int button,
                                   int action, int mods) {
  eventManager.mouseClickEvent.trigger(button, entityManager);
}
static void keyCallback(GLFWwindow *window, int key, int scanCode, int action,
                        int mods) {
  if (action != GLFW_PRESS)
    return;

  eventManager.keyboardEvent.trigger(key, entityManager);

  std::cout << "key: " << key << ", scan code: " << scanCode
            << ", action: " << action << ", mods: " << mods << "\n";
}
