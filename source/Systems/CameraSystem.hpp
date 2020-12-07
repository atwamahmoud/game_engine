//
// Created by atwa on 11/7/20.
//

#ifndef TEARS_ENGINE_CAMERA_SYSTEM_H
#define TEARS_ENGINE_CAMERA_SYSTEM_H

#include "../../vendor/glm/glm/glm.hpp"

#include "../../vendor/glm/glm/gtc/constants.hpp"
#include "../../vendor/glm/glm/trigonometric.hpp"
#include "../../vendor/glm/glm/gtx/fast_trigonometry.hpp"

#include "System.h"

class CameraSystem: public System {
    bool didSubscribe = false;
     float yaw, pitch;
        glm::vec3 position;

        float yaw_sensitivity, pitch_sensitivity, fov_sensitivity;
        glm::vec3 position_sensitivity;
        float speedup_factor = 5.0f; // A speed multiplier if "Left Shift" is held.

        bool mouse_locked = false;

    void update(EntityManager&, EventManager&, double) override;
    public:
     void initialize(){
            yaw_sensitivity = pitch_sensitivity = 0.01f;
            position_sensitivity = {3.0f, 3.0f, 3.0f};
            fov_sensitivity = 0.314/10;
            yaw = 0;
            pitch = 0;
        }

        void release(){
            if(mouse_locked) {
                mouse_locked = false;
            }
        }

        [[nodiscard]] float getYaw() const {return yaw;}
        [[nodiscard]] float getPitch() const {return pitch;}
        [[nodiscard]] glm::vec3 getPosition() const {return position;}

        [[nodiscard]] float getYawSensitivity() const {return yaw_sensitivity;}
        [[nodiscard]] float getPitchSensitivity() const {return pitch_sensitivity;}
        [[nodiscard]] float getFieldOfViewSensitivity() const {return fov_sensitivity;}
        [[nodiscard]] glm::vec3 getPositionSensitivity() const {return position_sensitivity;}
        [[nodiscard]] float getSpeedUpFactor() const {return speedup_factor;}

        void setYaw(float _yaw){
            this->yaw = glm::wrapAngle(_yaw);
        }
        void setPitch(float _pitch){
            const float v = 0.99f*glm::pi<float>()/2;
            if(_pitch > v) _pitch = v;
            else if(_pitch < -v) _pitch = -v;
            this->pitch = _pitch;
        }
        void setPosition(glm::vec3 _pos){
            this->position = _pos;
        }

        void setYawSensitivity(float sensitivity){this->yaw_sensitivity = sensitivity;}
        void setPitchSensitivity(float sensitivity){this->pitch_sensitivity = sensitivity;}
        void setFieldOfViewSensitivity(float sensitivity){this->fov_sensitivity = sensitivity;}
        void setPositionSensitivity(glm::vec3 sensitivity){this->position_sensitivity = sensitivity;}
};


#endif //TEARS_ENGINE_CAMERA_SYSTEM_H
