//
// Created by Henry Hicks on 11/19/25.
//

#include "CLIManager.hpp"
#include <kalon/Real.hpp>
#include <iostream>

namespace cli {


    bool CLIManager::RunInteractiveSetup() {
        std::cout << "Lambda Physics Engine CLI\n";
        std::cout << "-------------------------\n";

        // timestep
        std::cout << "Please enter the desired timestep (in seconds):";
        double dtInput;
        std::cin >> dtInput;
        if (dtInput <= 0) {
            std::cout << "Invalid timestep. Must be greater than zero.\n";
            return false;
        }
        _dt = kalon::Real(dtInput);

        // ascii
        std::cout << "Would you like to enable ASCII visualization? (y/n): ";
        char asciiAnswer;
        std::cin >> asciiAnswer;
        _asciiMode = (asciiAnswer == 'y' || asciiAnswer == 'Y');

        // scene
        std::cout << "Please select a scene (cradle, new, debug): ";
        std::cin >> _scene;

        return true;
    }
}


