# Lambda Physics Engine

A deterministic C++23 physics engine for research, built on the [kalon](https://github.com/smttyZ/kalon) math library. It's the second iteration of the physics behind [Project Lambda](https://github.com/smttyZ/Project-Lambda), restructured around pluggable scenes, with Newton's cradle as the first one.

> **Status: early skeleton, in active redesign.** The architecture is laid out, but there is no simulation loop yet, and the build currently stops on unfinished wiring between the CLI and the scene system.

## What's here

| Part | State |
|---|---|
| kalon integration (`kalon::Real` for all physical quantities) | ✅ Linked as a git submodule |
| Scene system: `IScene` interface, `SceneFactory`, `Empty` / `Cradle` / `Debug` scenes | 🚧 Interfaces and factory in place; scenes don't build bodies yet |
| Interactive CLI setup (timestep, scene, ASCII mode) | 🚧 In progress; doesn't compile yet |
| `PhysicsWorld` (`Initialize`, `Step(dt)`) | 🚧 Interface only |

## Design direction
- **Deterministic:** the same scene and timestep always produce the same result.
- **Scenes as presets:** each scene sets up the world for one experiment, so the engine doesn't special-case any of them. Newton's cradle is the first preset, not a hard-coded demo.
- **Strict numerics:** all physical quantities go through `kalon::Real`, which rejects NaN and infinity at the point they would appear.

## Layout
- `src/`: entry point
- `cli/`: interactive setup
- `physics/`: `PhysicsWorld` and the scene system
- `external/kalon/`: math library (git submodule)

## Building
Requires CMake ≥ 3.25 and a C++23 compiler. Clone with submodules:

```sh
git clone --recursive https://github.com/smttyZ/Lambda-Physics-Engine
cmake -B build
cmake --build build
```

(The build does not complete yet; see Status above.)

## License
Apache License 2.0. See [LICENSE](LICENSE).
