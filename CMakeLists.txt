cmake_minimum_required(VERSION 3.16)
project(tears_engine VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(vendor vendor/glfw/include vendor/glad/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)

add_executable(tears_engine
        source/main.cpp
        source/ShaderHandler.cpp
        source/ShaderHandler.h
        vendor/glad/src/gl.c source/common.h source/GameStateManager.cpp source/GameStateManager.h source/Entity/Entity.cpp source/Entity/Entity.h source/Components/Component.cpp source/Components/Component.h source/Systems/System.cpp source/Systems/System.h source/Entity/EntityManager.cpp source/Entity/EntityManager.h source/Systems/SystemManager.cpp source/Systems/SystemManager.h source/Events/Event.cpp source/Events/Event.h source/Events/EventManager.cpp source/Events/EventManager.h source/Events/MouseMoveEvent.cpp source/Events/MouseMoveEvent.h)

target_link_libraries(tears_engine glfw)