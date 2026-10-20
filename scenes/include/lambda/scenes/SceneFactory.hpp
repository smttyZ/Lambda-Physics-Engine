#pragma once

#include <memory>
#include "Scene.hpp"

namespace lambda::scenes {

class IScene;

std::unique_ptr<IScene> CreateScene(Scene scene);

} // namespace lambda::scenes
