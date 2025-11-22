//
// Created by Henry Hicks on 11/22/25.
//

#pragma once

namespace physics {
    class PhysicsWorld;
}

namespace physics::scenes {
    class IScene {
    public:
        virtual ~IScene() = default;

        virtual void BuildScene(PhysicsWorld& world) = 0;

        [[nodiscard]] virtual const char* GetName() const noexcept = 0;
    };
}