//
// Created by mahmoud on ٢‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_PROGRAM_H
#define TEARS_ENGINE_PROGRAM_H

#include "common.h"
#include "Events/MouseMoveEvent.h"
// #include <glm/glm.hpp>
// #include <glm/gtc/type_ptr.hpp>
#include "../vendor/glm/glm/glm.hpp"
#include "../vendor/glm/glm/gtc/type_ptr.hpp"

class Program {
    GLuint program;
    GLuint vertex_array;
    int shape = 1;
    MousePosition prevMousePosition = {
      .x =  0,
      .y =  0
    };
public:
    Program();
    void attachShader(string filename, GLenum type) const;
    void draw(MousePosition, int);
    void draw(int);
    //Get the location of a uniform variable in the shader
//    GLuint getUniformLocation(const std::string &name) {
//        // It is not efficient to ask OpenGL for Uniform location everytime we need them
//        // So the first time they are needed, we cache them in a map and reuse them whenever needed again
//        auto it = uniform_location_cache.find(name);
//        if(it != uniform_location_cache.end()){
//            return it->second; // We found the uniform in our cache, so no need to call OpenGL.
//        }
//        GLuint location = glGetUniformLocation(program, name.c_str()); // The uniform was not found, so we retrieve its location
//        uniform_location_cache[name] = location; // and cache the location for later queries
//        return location;
//    }
//
//    //A group of setter for uniform variables
//    //NOTE: It is inefficient to call glGetUniformLocation every frame
//    //So it is usually a better option to either cache the location
//    //or explicitly define the uniform location in the shader
//    void set(const std::string &uniform, GLfloat value) {
//        glUniform1f(getUniformLocation(uniform), value);
//    }
//
//    void set(const std::string &uniform, GLint value) {
//        glUniform1i(getUniformLocation(uniform), value);
//    }
//
//    void set(const std::string &uniform, GLboolean value) {
//        glUniform1i(getUniformLocation(uniform), value);
//    }
//
//    void set(const std::string &uniform, glm::vec2 value) {
//        glUniform2f(getUniformLocation(uniform), value.x, value.y);
//    }
//
//    void set(const std::string &uniform, glm::vec3 value) {
//        glUniform3f(getUniformLocation(uniform), value.x, value.y, value.z);
//    }
//
//    void set(const std::string &uniform, glm::vec4 value) {
//        glUniform4f(getUniformLocation(uniform), value.x, value.y, value.z, value.w);
//    }
//
//    void set(const std::string &uniform, glm::mat4 value, GLboolean transpose = false)  {
//        glUniformMatrix4fv(getUniformLocation(uniform), 1, transpose, glm::value_ptr(value));
//    }
};


#endif //TEARS_ENGINE_PROGRAM_H
