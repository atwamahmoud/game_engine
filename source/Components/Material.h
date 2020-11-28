//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_MATERIAL_H
#define TEARS_ENGINE_MATERIAL_H

#include <unordered_map>
#include "../common.h"
#include <vector>

#define _map std::unordered_map<string, std::vector<float>>

class Material {
public:
    Material(GLuint* shader, _map);
    GLuint* shader;
    _map uniformMap;
};

inline Material::Material(GLuint* shader, _map uniformMap) {
  this->shader = shader;
  this->uniformMap = uniformMap;
}


#endif //TEARS_ENGINE_MATERIAL_H
