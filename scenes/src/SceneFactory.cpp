#include "lambda/scenes/SceneFactory.hpp"

#include "lambda/scenes/IScene.hpp"
#include "lambda/scenes/SCradle.hpp"
#include "lambda/scenes/SEmpty.hpp"
#include "lambda/scenes/Scene.hpp"

namespace lambda::scenes {

std::unique_ptr<IScene> CreateScene(Scene scene) {
    switch (scene) {
        case Scene::Cradle:
            // TODO: pass parameters from the CLI (ball count, pull-back angle)
            return std::make_unique<SCradle>(25.0f);
        case Scene::Empty:
        case Scene::Debug:
        default:
            return std::make_unique<SEmpty>();
    }
}

} // namespace lambda::scenes
