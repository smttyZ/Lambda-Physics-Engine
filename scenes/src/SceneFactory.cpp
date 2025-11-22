#include "lambda/scenes/SceneFactory.hpp"

#include "lambda/scenes/IScene.hpp"
#include "lambda/scenes/Scene.hpp"
#include "lambda/physics/PhysicsWorld.hpp"

namespace lambda::scenes {

namespace {
class EmptyScene final : public IScene {
public:
    void BuildScene(lambda::physics::PhysicsWorld& /*world*/) override {}
};
} // namespace

std::unique_ptr<IScene> CreateScene(Scene scene) {
    switch (scene) {
        case Scene::Empty:
        default:
            return std::make_unique<EmptyScene>();
    }
}

} // namespace lambda::scenes
