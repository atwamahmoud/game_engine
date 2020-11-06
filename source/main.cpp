#include <iostream>
#include <zconf.h>
#include "common.h"
#include "Events/Event.h"
#include "Program.h"

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main() {

    glfwInit();

    //GLFW Config
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Make window size fixed (User can't resize it)
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    //Set Number of sample used in MSAA (0 = Disabled)
    glfwWindowHint(GLFW_SAMPLES, 0);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);

    //Set Bits for Stencil Buffer
    glfwWindowHint(GLFW_STENCIL_BITS, 8);

    //Set the refresh rate of the window (GLFW_DONT_CARE = Run as fast as possible)
    glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Phase 1", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    gladLoadGL(glfwGetProcAddress);


//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glfwSetCursorPosCallback(window, cursorPositionCallback);
//    glfwSetKeyCallback(window, keyCallback);



    Program prog;
    prog.draw();
    //Game Loop

    double startTime;
    double endTime = getTime();
    prog.draw();

    while(!glfwWindowShouldClose(window)){
        prog.draw();
//        startTime = getTime();
//        //Events...
//        glfwPollEvents();
//        //delta...
//        double delta = startTime - endTime;
////        std::cout<<"Time Taken to draw previous frame is: "<<delta<<"\n";
//        //Draw...
//        endTime = getTime();
    }

    return 0;
}

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    std::cout<<"x: "<<xpos<<", y: "<<ypos<<"\n";
}
static void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods) {
    if(action != GLFW_PRESS) return;
    std::cout<<"key: "<<key<<", scan code: "<<scanCode<<", action: "<<action<<", mods: "<<mods<<"\n";
}
