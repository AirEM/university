#ifndef CAMERAROTATOR_H
#define CAMERAROTATOR_H

#include "base_manager.h"
#include "../objects/camera/camera.h"

namespace managers {

using objects::Camera;

class CameraManager: public BaseManager {
public:
    void yaw(std::shared_ptr<Camera> camera, double angle);
    void roll(std::shared_ptr<Camera> camera, double angle);
    void pitch(std::shared_ptr<Camera> camera, double angle);
};

}

#endif // CAMERAROTATOR_H
