#include "cli/CLIManager.hpp"

#include <iostream>
#include <optional>
#include <string>

namespace cli {

namespace {

// Maps the names offered at the scene prompt to scenes.
std::optional<lambda::scenes::Scene> ParseScene(const std::string& name) {
    if (name == "cradle") return lambda::scenes::Scene::Cradle;
    if (name == "new") return lambda::scenes::Scene::Empty;
    if (name == "debug") return lambda::scenes::Scene::Debug;
    return std::nullopt;
}

} // namespace

bool CLIManager::RunInteractiveSetup() {
    std::cout << "Lambda Physics Engine CLI\n";
    std::cout << "-------------------------\n";

    // timestep
    std::cout << "Please enter the desired timestep (in seconds): ";
    double dtInput{};
    if (!(std::cin >> dtInput) || dtInput <= 0) {
        std::cout << "Invalid timestep. Must be a number greater than zero.\n";
        return false;
    }
    _dt = kalon::Real(dtInput);

    // ascii
    std::cout << "Would you like to enable ASCII visualization? (y/n): ";
    char asciiAnswer{};
    std::cin >> asciiAnswer;
    _asciiMode = (asciiAnswer == 'y' || asciiAnswer == 'Y');

    // scene
    std::cout << "Please select a scene (cradle, new, debug): ";
    std::string sceneName;
    std::cin >> sceneName;
    const auto scene = ParseScene(sceneName);
    if (!scene) {
        std::cout << "Unknown scene: " << sceneName << "\n";
        return false;
    }
    _scene = *scene;

    return true;
}

} // namespace cli
