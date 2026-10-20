#pragma once

#include "lambda/scenes/IScene.hpp"

namespace lambda::scenes {

class SEmpty final : public IScene {
public:
    void BuildScene(lambda::physics::PhysicsWorld& /*world*/) override {
        // nothing to do
    }

    [[nodiscard]] const char* GetName() const noexcept override { return "Empty Scene"; }
};

} // namespace lambda::scenes
