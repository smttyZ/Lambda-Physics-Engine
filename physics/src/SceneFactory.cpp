//
// Created by Henry Hicks on 11/22/25.
//

#include <memory>

#include "../include/scenes/SceneFactory.hpp"


namespace physics::scenes {
    std::unique_ptr<IScene> CreateScene(Scene scene) {
        switch (scene) {
            case Scene::Empty:
                return std::make_unique<SEmpty>();

            case Scene::Cradle:
                // Later you pass parameters from CLI (count, angle)
                return std::make_unique<SCradle>(5, 25.0f);

            case Scene::Debug:
            default:
                return std::make_unique<SEmpty>();
        }
    }
}
