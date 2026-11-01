#pragma once

#include "session.h"


struct State {
    struct Config {
        std::string filename;
    } config;

    struct DslFiles {
        std::string dslFilesSeparator = "-";
    } dslFiles;
};

struct Project {
    Project(uint8_t openings, const Path &path) : openings(openings), path(path) {}
    Project(const Path &path) : openings(1), path(path) {}

    uint8_t openings;
    Path path;
    State state;
};


SessionId openProject(const Path& projectRoot);
void closeProject(SessionId id);
