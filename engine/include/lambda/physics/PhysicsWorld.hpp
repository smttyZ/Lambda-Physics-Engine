#pragma once

namespace lambda::physics {

class PhysicsWorld {
public:
    PhysicsWorld() = default;
    ~PhysicsWorld() = default;

    void Initialize();
    void Step(double dt);
};

} // namespace lambda::physics
