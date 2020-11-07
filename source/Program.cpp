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

void Program::attachShader(string filename, GLenum type) const {

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

    attachShader("./assets/shaders/quad.vert", GL_VERTEX_SHADER);   // read the vertex shader and attach it to the program.
    attachShader("./assets/shaders/color.frag", GL_FRAGMENT_SHADER);      // read the fragment shader and attach it to the program.

    glLinkProgram(program);                     // Link the vertex and fragment shader together.
    checkProgramLinkingErrors(program);         // Check if there is any link errors between the fragment shader and vertex shader.

    glGenVertexArrays(1, &vertex_array);        // Ask GL to create a vertex array to easily create a triangle.


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Program::draw(MousePosition mousePosition) {

    if(mousePosition.x == prevMousePosition.x
        && mousePosition.y == prevMousePosition.y ) return;
    prevMousePosition = mousePosition;

    glm::vec2 scale = glm::vec2(1,1);
    glm::vec2 translation = glm::vec2(0,0);
    glm::vec3 color = glm::vec3(1, 0, 0);
    bool vibrate = false, flicker = false;

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);

    GLuint scale_uniform_location = glGetUniformLocation(program, "scale");
    glUniform2f(scale_uniform_location, scale.x, scale.y);
    GLuint translation_uniform_location = glGetUniformLocation(program, "translation");
    glUniform2f(translation_uniform_location, translation.x, translation.y);
    GLuint color_uniform_location = glGetUniformLocation(program, "color");
    glUniform3f(color_uniform_location, color.r, color.g, color.b);

    GLuint time_uniform_location = glGetUniformLocation(program, "time");
    glUniform1f(time_uniform_location, glfwGetTime());
    GLuint vibrate_uniform_location = glGetUniformLocation(program, "vibrate");
    glUniform1i(vibrate_uniform_location, vibrate);
    GLuint flicker_uniform_location = glGetUniformLocation(program, "flicker");
    glUniform1i(flicker_uniform_location, flicker);

    GLuint shape_uniform_location = glGetUniformLocation(program, "shape");
    glUniform1i(shape_uniform_location, shape);

    GLint loc = glGetUniformLocation(program, "iResolution");
    glUniform2f(loc, WINDOW_WIDTH, WINDOW_HEIGHT);//ah
    GLuint Mouse_uniform_location = glGetUniformLocation(program, "mouse");

    glUniform2f(Mouse_uniform_location, mousePosition.x, mousePosition.y); // -320 => 0


    glBindVertexArray(vertex_array);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Program::draw(int shape) {

    this->shape = shape;
    glm::vec2 scale = glm::vec2(1,1);
    glm::vec2 translation = glm::vec2(0,0);
    glm::vec3 color = glm::vec3(1, 0, 0);
    bool vibrate = false, flicker = false;

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);

    GLuint scale_uniform_location = glGetUniformLocation(program, "scale");
    glUniform2f(scale_uniform_location, scale.x, scale.y);
    GLuint translation_uniform_location = glGetUniformLocation(program, "translation");
    glUniform2f(translation_uniform_location, translation.x, translation.y);
    GLuint color_uniform_location = glGetUniformLocation(program, "color");
    glUniform3f(color_uniform_location, color.r, color.g, color.b);

    GLuint time_uniform_location = glGetUniformLocation(program, "time");
    glUniform1f(time_uniform_location, glfwGetTime());
    GLuint vibrate_uniform_location = glGetUniformLocation(program, "vibrate");
    glUniform1i(vibrate_uniform_location, vibrate);
    GLuint flicker_uniform_location = glGetUniformLocation(program, "flicker");
    glUniform1i(flicker_uniform_location, flicker);

    GLuint shape_uniform_location = glGetUniformLocation(program, "shape");
    glUniform1i(shape_uniform_location, shape);

    GLint loc = glGetUniformLocation(program, "iResolution");
    glUniform2f(loc, WINDOW_WIDTH, WINDOW_HEIGHT);//ah
    GLuint Mouse_uniform_location = glGetUniformLocation(program, "mouse");

    glUniform2f(Mouse_uniform_location, prevMousePosition.x, prevMousePosition.y); // -320 => 0

    glBindVertexArray(vertex_array);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}