cmake_minimum_required(VERSION 3.16)
project(tears_engine VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(vendor vendor/utils/tinyobj vendor/glm vendor/glfw/include vendor/glad/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

add_executable(tears_engine
        source/main.cpp
        source/Events/MouseClickEvent.h
        source/Events/MouseClickEvent.cpp
        source/Program.cpp
        source/Program.h
        source/GameState.h
        vendor/glad/src/gl.c
        source/common.h
        source/GameStateManager.cpp
        source/GameStateManager.h
        source/Entity/Entity.cpp
        source/Entity/Entity.h
        source/Components/Component.cpp
        source/Components/Component.h
        source/Systems/System.cpp
        source/Systems/System.h
        source/Entity/EntityManager.cpp
        source/Entity/EntityManager.h
        source/Systems/SystemManager.cpp
        source/Systems/SystemManager.h
        source/Events/Event.cpp
        source/Events/Event.h
        source/Events/EventManager.cpp
        source/Events/EventManager.h
        source/Events/MouseMoveEvent.cpp
        source/Events/MouseMoveEvent.h
        source/Systems/MovementSystem.cpp
        source/Systems/MovementSystem.h
        source/Components/Position.cpp
        source/Components/Position.h
        source/Systems/ProgramSystem.cpp
        source/Systems/ProgramSystem.h
        source/Systems/SelectionSystem.cpp
        source/Systems/SelectionSystem.h
        source/Events/MouseMoveEvent.cpp
        source/Events/MouseMoveEvent.h
        source/Events/KeyboardEvent.cpp
        source/Events/KeyboardEvent.h
        source/camera/camera.hpp
        source/camera/controllers/fly_camera_controller.hpp
        source/camera/controllers/orbit_camera_controller.hpp
        source/mesh/common-vertex-attributes.hpp
        source/mesh/common-vertex-types.hpp
        source/mesh/mesh-utils.hpp
        source/mesh/mesh-utils.cpp
        source/mesh/vertex-attributes.hpp
        source/Components/MeshRenderer.h
        source/Components/Material.h
        source/Systems/CameraSystem.cpp
        source/Systems/CameraSystem.hpp
        source/Systems/RenderSystem.cpp
        source/Systems/RenderSystem.h
        source/Systems/TransformSystem.cpp
        source/Systems/TransformSystem.h
        source/Components/TransformComponent.cpp
        source/Components/TransformComponent.h
        source/MenuState.cpp source/MenuState.h source/PlayState.cpp source/PlayState.h)

target_link_libraries(tears_engine glfw)