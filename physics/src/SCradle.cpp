//
// Created by Henry Hicks on 11/22/25.
//
#include "../include/scenes/SCradle.hpp"

namespace physics {
    class PhysicsWorld;
}

namespace physics::scenes {
    SCradle::SCradle(float d_pullBackAngle) : _d_pullBackAngle(d_pullBackAngle) {

    }

    auto SCradle::BuildScene(PhysicsWorld &world) -> void {

    }

    const char* SCradle::GetName() const noexcept {
        return "Newton's Cradle";
    }
}
