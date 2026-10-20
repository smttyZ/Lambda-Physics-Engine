#include "cli/CLIManager.hpp"

int main() {
    cli::CLIManager cli;
    if (!cli.RunInteractiveSetup()) {
        return 1;
    }
    return 0;
}
