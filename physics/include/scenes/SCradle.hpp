//
// Created by Henry Hicks on 11/22/25.
//

#pragma once

#include "IScene.hpp"

namespace physics::scenes {

    class SCradle : public IScene {
    public:
        // TODO: will be replaced by Angle type
        explicit SCradle(float d_pullBackAngle);

        void BuildScene(PhysicsWorld& world) override;
        [[nodiscard]] const char* GetName() const noexcept override;

    private:
        float _d_pullBackAngle{};
    };
}
