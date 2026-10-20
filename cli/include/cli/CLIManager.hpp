#pragma once

#include <string>

#include <kalon/Real.hpp>

#include "lambda/scenes/Scene.hpp"

namespace cli {

class CLIManager {
public:
    CLIManager() = default;
    ~CLIManager() = default;

    /**
     * @brief Runs the interactive setup phase.
     * Prompts the user for configuration (timestep, ASCII mode, scene).
     * @return true if setup completed successfully.
     */
    bool RunInteractiveSetup();

    /**
     * @brief Get the timestep selected by the user.
     */
    [[nodiscard]] kalon::Real GetTimestep() const noexcept { return _dt; }

    // getters
    [[nodiscard]] std::string GetBuffer() const noexcept { return _buffer; }
    void SetBuffer(const std::string& buffer) noexcept { _buffer = buffer; }

    [[nodiscard]] bool UseASCII() const noexcept { return _asciiMode; }
    [[nodiscard]] lambda::scenes::Scene GetScene() const noexcept { return _scene; }

private:
    kalon::Real _dt{};
    std::string _buffer{};
    bool _asciiMode{};
    lambda::scenes::Scene _scene{};
};

} // namespace cli
