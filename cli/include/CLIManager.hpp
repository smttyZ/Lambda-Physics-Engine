#pragma once
#include <string>
#include "kalon/Real.hpp"

namespace cli {

    class CLIManager {
    public:
        CLIManager() = default;
        ~CLIManager() = default;

        /**
         * @brief Runs the interactive setup phase.
         * Prompts the user for configuration (e.g., timestep).
         * @return true if setup completed successfully.
         */
        bool RunInteractiveSetup();

        /**
         * @brief Get the timestep selected by the user.
         */
        [[nodiscard]] kalon::Real GetTimestep() const noexcept;

        // getters
        [[nodiscard]] std::string GetBuffer() const noexcept { return _buffer; }
        void SetBuffer(const std::string& buffer) noexcept { _buffer = buffer; }

        [[nodiscard]] bool UseASCII() const noexcept { return _asciiMode; }

        [[nodiscard]] physics::Scene GetScene() const noexcept { return _scene; }

    private:
        kalon::Real _dt{};
        std::string _buffer{};
        bool _asciiMode{};
        physics::Scene _scene{};
    };

} // namespace cli