#include "project.h"
#include "error.h"
#include <map>
#include <stdexcept>


namespace {
    std::map<ProjectHash, Project>& getProjectsMap() {
        static std::map<ProjectHash, Project> projects;
        return projects;
    }
}

static bool projectExists(const ProjectHash& projectHash) {
    return getProjectsMap().contains(projectHash);
}

SessionId openProject(const Path& projectRoot) {
    SessionId sessionId = newSession(projectRoot);
    ProjectHash projectHash = sessionId.parts.projectHash;

    auto& projects = getProjectsMap();
    auto& project = projects[projectHash];

    if (project.openings == 0 && project.path.empty()) {
        project.path = projectRoot;
    }

    project.openings++;
    return sessionId;
}

void closeProject(SessionId sessionId) {
    ProjectHash projectHash = sessionId.parts.projectHash;
    auto& projects = getProjectsMap();

    auto it = projects.find(projectHash);
    if (it != projects.end()) {
        it->second.openings--;
        if (it->second.openings == 0) {
            projects.erase(it);
        }
        return;
    }

    throw std::runtime_error("No project found for this session");
}