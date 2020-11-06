//
// Created by Mahmoud Atwa on 02/11/2020
//

#include "Program.h"

string readFile(string filename) {
    std::ifstream fin(filename);
    if(fin.fail()){
        std::cerr << "Unable to open shader file: " << filename << std::endl;
        std::exit(-1);
    }
    return string(std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>());
}


void checkProgramLinkingErrors(GLuint program){
    //Check and log for any error in the linking process.
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);               // Takes a shader program (vertex & fragment) and returns the status of this shader program.
    if (!status)                                                    // If there is a status (status != 0):
    {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);       // Get the error length (char array length).
        char* logStr = new char[length];
        glGetProgramInfoLog(program, length, nullptr, logStr);      // Get the error char array.
        std::cerr << "LINKING ERROR: " << logStr << std::endl;      // print the char array of the log error.
        delete[] logStr;
        std::exit(-1);
    }
}


void checkShaderCompilationErrors(GLuint shader) {
    //Check and log for any error in the compilation process.
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS,
                  &status);          // Takes a shader and returns the status of this shader program.
    if (!status) {                                                // If there is a status (status != 0):
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);     // Get the error length (char array length).
        char *logStr = new char[length];
        glGetShaderInfoLog(shader, length, nullptr, logStr);    // Get the error char array.
        std::cerr << "ERROR:" << logStr << std::endl;           // print the char array of the log error.
        delete[] logStr;
        std::exit(-1);
    }
}

void Program::attachShader(string filename, GLenum type) {

    // 1. Reads the shader from file, compiles it,
    std::string source_code = readFile(filename);
    const char* source_code_as_c_str = source_code.c_str();

    // 2. Pass the program as a string to the GPU and then compile it.
    GLuint shader = glCreateShader(type);
    // Function parameter:
    // shader (GLuint): shader object name.
    // count (GLsizei): number of strings passed in the third parameter. We only have one string here.
    // string (const GLchar**): an array of source code strings.
    // lengths (const GLint*): an array of string lengths for each string in the third parameter. if null is passed,
    //                          then the function will deduce the lengths automatically by searching for '\0'.
    glShaderSource(shader, 1, &source_code_as_c_str, nullptr);
    glCompileShader(shader);

    // 3. Check for any Compilation errors.
    checkShaderCompilationErrors(shader);

    // 4. Attach this shader to the program if no errors found in shader.
    glAttachShader(program, shader);

    // 5. Delete the shader as it is already attached to the program.
    glDeleteShader(shader);
}

Program::Program() {
    program = glCreateProgram();    // We ask GL to create a program for us and return a uint that we will use it by.
    // (act as a pointer to the created program).

    attachShader("./assets/shaders/ex02_shader_introduction/triangle.vert", GL_VERTEX_SHADER);   // read the vertex shader and attach it to the program.
    attachShader("./assets/shaders/ex02_shader_introduction/red.frag", GL_FRAGMENT_SHADER);      // read the fragment shader and attach it to the program.

    glLinkProgram(program);                     // Link the vertex and fragment shader together.
    checkProgramLinkingErrors(program);         // Check if there is any link errors between the fragment shader and vertex shader.

    glGenVertexArrays(1, &vertex_array);        // Ask GL to create a vertex array to easily create a triangle.

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);       // Set the clear color
}

void Program::draw() {
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the frame buffer (back buffer of the window)
    glUseProgram(program);                      // Ask GL to use this program for the upcoming operations.
    // Every shader and rendering call after glUseProgram will now use this program object (and the shaders).

    glBindVertexArray(vertex_array);            // Binding is like selecting which object to use.
    // Note that we need to bind a vertex array to draw
    // Even if that vertex array does not send any data down the pipeline

    // Sends vertices down the pipeline for drawing
    // Parameters:
    // mode (GLenum): what primitives to draw. GL_TRIANGLES will combine each 3 vertices into a triangle.
    // first (GLint): the index of the first vertex to draw. It is useless here since we are not receiving data through the vertex array.
    // count (GLsizei): How many vertices to send to the pipeline. Since we are sending 3 vertices only, only one triangle will be drawn.
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);                       // Unbind the buffer.
}
