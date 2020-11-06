//
// Created by mahmoud on ٢‏/١١‏/٢٠٢٠.
//

#ifndef TEARS_ENGINE_PROGRAM_H
#define TEARS_ENGINE_PROGRAM_H

#include "common.h"

class Program {
    GLuint program = 0;
    GLuint vertex_array = 0;
public:
    Program();
    void attachShader(string filename, GLenum type);
    void draw();
};


#endif //TEARS_ENGINE_PROGRAM_H
