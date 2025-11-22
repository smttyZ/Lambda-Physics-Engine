//
// Created by Henry Hicks on 11/17/25.
//

#pragma once

#include <kalon/Real.hpp>

namespace lambda::physics {
    class PhysicsWorld {
    public:
        PhysicsWorld() = default;
        virtual ~PhysicsWorld() = default;

        void Initialize();

        void Step(kalon::Real dt);
    };
}