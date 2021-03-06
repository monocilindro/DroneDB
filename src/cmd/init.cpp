/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "init.h"

#include <iostream>

#include "ddb.h"
#include "fs.h"

namespace cmd {

void Init::setOptions(cxxopts::Options &opts) {
    // clang-format off
    opts
    .positional_help("[args] [DIRECTORY]")
    .custom_help("init")
    .add_options()
    ("w,working-dir", "Working directory", cxxopts::value<std::string>()->default_value("."));
    // clang-format on
    opts.parse_positional({"working-dir"});
}

std::string Init::description() {
    return "Initialize an index. If a directory is not specified, initializes "
           "the index in the current directory";
}

void Init::run(cxxopts::ParseResult &opts) {
    std::string p = opts["working-dir"].as<std::string>();
    char *outPath;
    if (DDBInit(p.c_str(), &outPath) == DDBERR_NONE) {
        std::cout << "Initialized empty database in " << outPath << std::endl;
    } else {
        std::cerr << DDBGetLastError() << std::endl;
    }
}

}  // namespace cmd
