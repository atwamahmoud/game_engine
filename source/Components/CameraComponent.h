//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_CAMERA_COMPONENT_H
#define TEARS_ENGINE_CAMERA_COMPONENT_H


#include "Component.h"
#include <vector>


enum Projection {
  Orthographic,
  Perspective
};

class CameraComponent: public Component {
public:
  Projection projection;
  // Field of view is ignored when camera is orthographic
  float verticalFOV;
  // Credits to:: @neginfinity, https://forum.unity.com/threads/adjust-fov-based-on-aspect-ratio-how.474627/
  // aspectRatio = tan(hFov * 0.5f)/tan(vFov*0.5f);
  float nearPlane;
  float farPlane;
};


#endif //TEARS_ENGINE_CAMERA_COMPONENT_H
