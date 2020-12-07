#ifndef TEARS_ENGINE_MESH_UTILS_H
#define TEARS_ENGINE_MESH_UTILS_H

#include "../Mesh.hpp"

#include "../../vendor/glm/glm/glm.hpp"

namespace mesh_utils {

    // Load an ".obj" file into the mesh
    bool loadOBJ(Mesh& mesh, const char* filename);

    void Cuboid(Mesh& mesh, bool colored_faces = false,
                const glm::vec3& center = {0,0,0},
                const glm::vec3& size = {1,1,1},
                const glm::vec2& texture_offset = {0, 0},
                const glm::vec2& texture_tiling = {1, 1});

    void Sphere(Mesh& mesh,
                const glm::ivec2& segments = {32, 16},
                bool colored = false,
                const glm::vec3& center = {0,0,0},
                float radius = 0.5f,
                const glm::vec2& texture_offset = {0, 0},
                const glm::vec2& texture_tiling = {1, 1});

    void Plane(Mesh& mesh,
               const glm::ivec2& resolution = {1, 1},
               bool colored = false,
               const glm::vec3& center={0, 0, 0},
               const glm::vec2& size={1, 1},
               const glm::vec2& texture_offset = {0, 0},
               const glm::vec2& texture_tiling = {1, 1});

}

#endif //OUR_MESH_UTILS_H
