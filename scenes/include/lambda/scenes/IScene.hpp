#pragma once

namespace lambda::physics {
class PhysicsWorld;
}

namespace lambda::scenes {

class IScene {
public:
    virtual ~IScene() = default;
    virtual void BuildScene(lambda::physics::PhysicsWorld& world) = 0;
};

} // namespace lambda::scenes
