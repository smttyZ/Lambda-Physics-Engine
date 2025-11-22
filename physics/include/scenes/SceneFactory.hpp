//
// Created by Henry Hicks on 11/22/25.
//

#pragma once

#include <memory>
#include "Scene.hpp"
#include "SEmpty.hpp"
#include "SCradle.hpp"

namespace physics::scenes {

    std::unique_ptr<IScene> CreateScene(Scene scene);

}