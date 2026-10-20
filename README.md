# Lambda Physics Engine

A deterministic C++23 physics engine for research, built on the [kalon](https://github.com/smttyZ/kalon) math library. It's the second iteration of the physics behind [Project Lambda](https://github.com/smttyZ/Project-Lambda), restructured around pluggable scenes, with Newton's cradle as the first one.

> **Status: early skeleton.** It builds warning-free and runs an interactive setup, but there's no simulation loop yet: `PhysicsWorld::Step` and the scenes' `BuildScene` are still TODOs.

## What's here

| Part | State |
|---|---|
| `engine/`: `PhysicsWorld` (`Initialize`, `Step(kalon::Real dt)`) | 🚧 Interface in place; no simulation yet |
| `scenes/`: `IScene`, `SceneFactory`, `SEmpty`, `SCradle` (pull-back angle) | 🚧 Factory works; scenes don't create bodies yet |
| `cli/`: interactive setup (timestep, ASCII mode, scene) | ✅ Works. `ArgParser` for command-line flags is included but not wired up yet |
| kalon (`kalon::Real` for physical quantities) | ✅ Git submodule, linked through `engine` |
| `tests/`: unit + integration | Planned, empty |

## Design direction
- **Deterministic:** the same scene and timestep always produce the same result.
- **Scenes as presets:** each scene sets up the world for one experiment, so the engine doesn't special-case any of them.
- **Strict numerics:** physical quantities go through `kalon::Real`, which rejects NaN and infinity at the point they would appear.

See [ROADMAP.md](ROADMAP.md) for what's next.

## Building
Requires CMake ≥ 3.25 and a C++23 compiler (tested with GCC 13 and Clang 18). Warnings are errors by default (`-DENABLE_WARNINGS_AS_ERRORS=OFF` to relax).

```sh
git clone --recursive https://github.com/smttyZ/Lambda-Physics-Engine
cd Lambda-Physics-Engine
cmake -B build
cmake --build build
./build/lambda_physics
```

## License
Apache License 2.0. See [LICENSE](LICENSE).
