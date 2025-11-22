//
// Created by Henry Hicks on 11/22/25.
//

#pragma once
#include "IScene.hpp"

namespace physics::scenes {
    class SEmpty : public IScene {
    public:
        void BuildScene(PhysicsWorld& world) override {
            // nothing to do
        }

        [[nodiscard]] const char* GetName() const noexcept override { return "Empty Scene"; }
    };
}