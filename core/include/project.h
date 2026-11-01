#pragma once
#include <filesystem>
#include <map>

#include "session.h"


struct State {
    std::string dslFilesSeparator = "-";
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
