//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_MESH_RENDERER_H
#define TEARS_ENGINE_MESH_RENDERER_H

#include "../Mesh.hpp"
#include "Material.h"

class MeshRenderer {
public:
  Mesh *mesh;
  Material *material;
  MeshRenderer(Mesh *&, Material *&);
};

inline MeshRenderer::MeshRenderer(Mesh *&mesh, Material *&mat) {
  this->mesh = mesh;
  this->material = mat;
}

#endif // TEARS_ENGINE_MESH_RENDERER_H
