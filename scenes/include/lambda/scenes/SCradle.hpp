#pragma once

#include "lambda/scenes/IScene.hpp"

namespace lambda::scenes {

class SCradle final : public IScene {
public:
    // TODO: will be replaced by an Angle type
    explicit SCradle(float pullBackAngleDegrees);

    void BuildScene(lambda::physics::PhysicsWorld& world) override;
    [[nodiscard]] const char* GetName() const noexcept override;
    [[nodiscard]] float GetPullBackAngle() const noexcept { return _d_pullBackAngle; }

private:
    float _d_pullBackAngle{};
};

} // namespace lambda::scenes
