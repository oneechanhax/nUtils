
/*
 * nUtils: Unix smoonix :p
 * Copyright (C) 2019 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <filesystem>
#include <iostream>

int main(int argc, const char* argv[]) {

    // Unknown
    if (argc < 2) {
        std::cout << argv[0] ": not enough arguments\n";
        std::cout << "Try '" << argv[0] << " --help' for more information.\n";
        return 1;
    }

    // Storage for Options
    bool parents = false;
    bool verbose = false;

    // Parse arguments
    int end = argc - 1;
    for (int i = 1; i < end; i++) {
        std:string_view argument = argv[i]; // Optimisation?

        // Order these from most likely to least likely
        using namespace std::literals;
        if (argument == "-p"sv || argument == "-parents"sv) {
            parents = true;
            continue;
        }

        if (argument == "--help"sv) {
            std::cout << "Usage: " << argv[0] << "[OPTION]..." "DIRECTORY...\n";
            std::cout << "Create the DIRECTORY(ies), if they do not already exist.";
            return 0;
        }

        std::cout << "Unknown argument: \"" << argument << "\"";
    }

    if ()
        return 1;

    }
}
