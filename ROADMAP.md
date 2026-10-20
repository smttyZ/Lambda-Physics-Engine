# Roadmap

Open work for the Lambda Physics Engine, roughly in order. Completed items from the earlier readiness plan (build layout, namespaces, CLI scene parsing, kalon packaging and tests, warnings-as-errors) have been removed; see git history for the original.

## Physics
- Port the prototype physics from [Project-Lambda](https://github.com/smttyZ/Project-Lambda) onto kalon: rigid bodies, sphere/AABB colliders, velocity Verlet integration, and its tests.
- Give `PhysicsWorld` real state (bodies, constraints, integrator) and a deterministic `Step(kalon::Real dt)`.
- Establish a units policy (SI) and document how `kalon::Real` and vectors carry units; convert only at the boundaries.

## Scenes
- Build scenes from a common template (base class), so each scene only describes its own setup.
- Make Newton's cradle a real scene: implement `SCradle::BuildScene` with parameters (ball count, spacing, pull-back angle).
- Consider a `SceneGraph` or entity abstraction so setup isn't hard-coded in scene classes.

## CLI
- Add non-interactive flags for automation (e.g. `--scene cradle --dt 0.001 --ascii`), keeping the interactive prompts optional. `cli::ArgParser` is the starting point.
- Put ASCII/terminal rendering behind an interface so it can be swapped for headless batch runs.

## Testing
- Scene construction tests: body counts, initial energy, cradle symmetry.
- Deterministic regression tests: step a scene and compare energies/momenta against snapshots.

## Math (kalon)
- Strongly typed units and an exception-free path for GPU work (see kalon's README).
- Comparison tolerances for `Real` (epsilon/ULP-aware), and serialization for logging and CLI display.

## Tooling & docs
- Commit `clang-format`/`clang-tidy` configs; add CI (build + tests on GCC and Clang).
- `docs/`: coordinate systems, units, integrators, and scene conventions; experiment configs for common runs.
- Optional: a top-level Dockerfile for reproducible headless runs.
