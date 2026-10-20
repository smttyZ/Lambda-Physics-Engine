#include "lambda/scenes/SCradle.hpp"

namespace lambda::scenes {

SCradle::SCradle(float pullBackAngleDegrees) : _d_pullBackAngle(pullBackAngleDegrees) {}

void SCradle::BuildScene(lambda::physics::PhysicsWorld& /*world*/) {
    // TODO: create the bobs and their suspensions
}

const char* SCradle::GetName() const noexcept {
    return "Newton's Cradle";
}

} // namespace lambda::scenes
