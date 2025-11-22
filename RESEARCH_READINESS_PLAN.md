# Lambda Physics Engine – Research-Grade Readiness Plan

This document is an actionable checklist to harden the Lambda Physics Engine (and the `external/kalon` math library) so they compile reliably on Linux (preferably in Docker) and are suitable for reproducible research. Tasks are ordered so that build correctness comes first, then API/architecture, then testing and tooling.

## 1) Baseline build + project layout
- Collapse the engine into two libraries: `engine` (core physics) and `cli` (UI), then have `lambda_physics` as a thin executable. Avoid adding headers to `add_executable` sources; list only translation units.
- Fix include paths: expose `physics/include` and `cli/include` via `target_include_directories`; drop the unused `${PROJECT_SOURCE_DIR}/include`. Add an interface target for `physics` headers if you want header-only scenes.
- Align namespaces: `PhysicsWorld` lives in `lambda::physics`, while scenes live in `physics::scenes`. Pick one namespace root (`lambda::physics`) and apply it consistently across headers/impls.
- Resolve type visibility: `cli/CLIManager` uses `physics::Scene` without including `Scene.hpp`, and `std::cin >> _scene` lacks an extraction operator. Decide on CLI-facing enums/structs and expose them cleanly.
- Build system hygiene: promote `/cmake-build-debug` to `.gitignore` and keep the build tree out of source. Remove stray binaries such as `external/kalon/a.out`.

## 2) Physics engine scaffolding
- Define a minimal, compilable `PhysicsWorld` with state (bodies, constraints, integrator) and stubbed methods. Provide a deterministic step signature (`Step(kalon::Real dt)`).
- Finish scene interfaces: implement `SCradle::BuildScene`, add parameterization (mass count, spacing, pullback angle), and wire factory defaults via CLI options.
- Add a `SceneGraph` or `Entity` abstraction early to avoid hardcoding setup in scene classes.
- Establish units policy (SI) and document how `kalon::Real` and vectors carry units; ensure conversions happen at the boundaries.

## 3) Math library (external/kalon)
- Stabilize `Real` semantics: clarify implicit vs explicit conversions, NaN/inf handling, and comparison tolerances (ULP/epsilon-aware comparisons).
- Complete vector/matrix types: finish cross/dot/normalize with cache invalidation, add unit-safe scalar ops, and supply serialization utilities for logging and CLI display.
- Add CMake options: `KALON_ENABLE_TESTS`, `KALON_BUILD_DOCS`, `KALON_WARNINGS_AS_ERRORS`. Export a proper `kalonConfig.cmake` usable by parent projects.
- Remove the embedded `.git` directory if this is vendored; otherwise treat Kalon as a submodule with its own CI.

## 4) Tooling, quality, and style
- Adopt a formatter (`clang-format`) and linter (`clang-tidy`) with a committed config. Wire them into the build (`cmake -DENABLE_CLANG_TIDY=ON` option).
- Enable warnings-as-errors for the engine/CLI targets and standardize on `-Wall -Wextra -Wpedantic` (plus clang static analyzer in CI).
- Add Doxygen (or Sphinx + Breathe) for API docs; ensure every public type/function has a brief. Generate docs in CI artifacts.
- Provide logging/tracing hooks (e.g., spdlog) and metrics counters to support research-grade experiment runs.

## 5) Testing and verification
- Create unit tests for `kalon::Real`, vectors, and scene construction using GoogleTest (already hinted in Kalon Dockerfile). Gate merges on passing tests.
- Add integration tests for scene setup: verify body counts, initial energy, and symmetry for the cradle.
- Introduce deterministic regression tests: run small time steps and snapshot energies/momenta for comparison.
- Consider property-based tests (rapidcheck/CppQuickCheck) for vector algebra invariants.

## 6) CLI and UX polish
- Separate configuration parsing from I/O. Provide non-interactive flags for automation (`--scene cradle --dt 0.001 --ascii false`), keeping interactive prompts optional.
- Implement `operator>>` for the scene enum or replace with a typed parser; validate inputs with clear error messages.
- Add ASCII/terminal rendering behind an interface so it can be swapped for headless batch runs.

## 7) Docker and Linux compatibility
- Add a root-level `Dockerfile` for the whole project (reusing the Kalon base): Ubuntu 24.04, `clang-16/17`, `cmake`, `ninja`, `libgtest-dev`. Build steps:
  ```sh
  docker build -t lambda-physics .
  docker run --rm -it lambda-physics ./build/lambda_physics --help
  ```
- Include a `docker-compose.yml` (optional) for running headless simulations with mounted volumes for results.
- Document a bare-metal Linux build path: `cmake -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build -j$(nproc) && ctest --output-on-failure`.

## 8) Documentation and reproducibility
- Write an overview in `docs/` that explains coordinate systems, units, integrators, and scene conventions.
- Add experiment templates: config files for common runs (cradle with N=5, pullback=25°; empty/debug scenes), plus instructions for reproducing plots.
- Publish a `CONTRIBUTING.md` with coding standards, review expectations, and branching strategy.
- Track open questions and TODOs in issues instead of inline comments once triaged.

## 9) Immediate blockers to compilation
- Namespace mismatch (`lambda::physics` vs `physics::scenes`) prevents linking.
- Missing include and extraction operator for `Scene` in `cli/CLIManager` makes the CLI non-compilable.
- `SceneFactory` currently constructs `SCradle` with two arguments, but `SCradle` only accepts one; harmonize the constructor and factory signature.
- `target_include_directories` does not expose `physics/include`; headers may not be found on Linux.

## 10) Suggested next sprint (concrete steps)
1. Normalize namespaces and headers; fix the Scene enum plumbing so the project builds end-to-end on Linux.
2. Restructure CMake into `kalon` (interface), `engine` (static), `cli` (static), `lambda_physics` (exe); add warning flags and a top-level Dockerfile.
3. Implement minimal `PhysicsWorld` state + `SCradle::BuildScene`, plus a smoke-test that constructs each scene.
4. Add `clang-format`/`clang-tidy` configs and a GitHub Actions CI matrix (Linux/clang/gcc) running build + tests + format check.
5. Start docs: `docs/overview.md` (architecture, units) and `docs/build.md` (Docker + bare-metal instructions).

Following this plan will make the codebase compilable on Linux, reproducible in Docker, and ready for research workflows where correctness, logging, and repeatability are mandatory.
