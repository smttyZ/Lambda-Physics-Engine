//
// Created by Henry Hicks on 11/22/25.
//

#pragma once

namespace physics::scenes {
    enum class Scene {
        Empty,
        Cradle,
        Debug,
        none // shouldn't ever be used, but in case something goes wrong with the factory
    };
}