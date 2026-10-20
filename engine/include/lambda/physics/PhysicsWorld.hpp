#pragma once

#include <kalon/Real.hpp>

namespace lambda::physics {

class PhysicsWorld {
public:
    PhysicsWorld() = default;
    ~PhysicsWorld() = default;

    void Initialize();
    void Step(kalon::Real dt);
};

} // namespace lambda::physics
