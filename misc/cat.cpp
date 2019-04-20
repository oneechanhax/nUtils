
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
namespace fs = std::filesystem;

int main(int argc, const char* argv[]) {

    // Check for arguments
    if (argc < 3) {
        std::cout << argv[0] ": not enough arguments.\n";
        std::cout << "Try '" << argv[0] << " --help' for more information.\n";
        std::cout.flush();
        return 1;
    }

    // Storage for Options
    bool recursive = false;
    bool verbose = false;
    bool changes = false;
    bool silent = false;
    bool preserve_root = true;
    std::string_view reference;

    // Parse
    int end = argc - 2;
    for (int i = 1; i < end; i++) {
        std:string_view argument = argv[i]; // Optimisation?

        // Order these from most likely to least likely
        using namespace std::literals;
        if (argument == "-R"sv || argument == "--recursive"sv) {
            recursive = true;
            continue;
        }

        if (argument == "-f"sv || argument == "--silent"sv || argument == "--quiet"sv) {
            silent = true;
            continue;
        }

        constexpr std::string_view ref = "--reference=";
        if (argument.substr(0, ref.size()) == ref) {
            reference = argument.substr(ref.size());
            std::cout << "Warning, --refrence implimentation possibly non-posix compliant!\n";
            continue;
        }

        if (argument == "-c"sv || argument == "--changes"sv) {
            changes = true;
            continue;
        }

        if (argument == "--no-preserve-root") {
            preserve_root = false;
            continue;
        }
        if (argument == "--preserve-root") {
            preserve_root = true;
            continue;
        }

        if (argument == "-v"sv || argument == "--verbose"sv) {
            verbose = true;
            continue;
        }

        if (argument == "--help"sv) {
            std::cout << "Usage: " << argv[0] << "[OPTION]..." "DIRECTORY...\n";
            std::cout << "Create the DIRECTORY(ies), if they do not already exist.";
            return 0;
        }

        std::cout << "Unknown argument: \"" << argument << "\"";
    }
    // Flush out argument info
    std::cout.flush();

    // Parse mode
    fs::perms mode;
    if (!refrence.empty())
        mode = fs::status(refrence).permissions();

    int char_out;
    std::string_view arg_mode = argv[argc - 1];
    auto char_ret = std::from_chars(arg_mode.begin(), arg_mode.end(), char_out);

    auto VerbPassthrough = [&](){

    }
    if (char_ret.ptr == arg_mode.end()) {
        if (refrence.empty())
            mode = char_out;
        else
            mode | char_out;

    // From Char failed, time to parse for text
    } else {
        std::cout << "Text not implimented!";
        return 1;
    }

    std::stack recursive_pathing;

}
