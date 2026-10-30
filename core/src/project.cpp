#include "project.h"

#include "error.h"

static bool projectExists(const ProjectHash projectHash) {
    return projects.contains(projectHash);
}

static void addProject(const ProjectHash projectHash, const Project& project) {
    projects.insert({projectHash, project});
}

static void removeProject(const ProjectHash projectHash) {
    projects.erase(projectHash);
}

static Project& getProject(const ProjectHash projectHash) {projects[projectHash]; }

SessionId openProject(const Path& projectRoot) {
    SessionId sessionId = newSession(projectRoot);
    ProjectHash projectHash = sessionId.parts.projectHash;
    if (projectExists(projectHash)) getProject(projectHash).openings++;
    addProject(sessionId.parts.projectHash, Project(projectRoot));
    return sessionId;
}

void closeProject(SessionId sessionId) {
    ProjectHash projectHash = sessionId.parts.projectHash;
    if (projectExists(projectHash)) {
        getProject(projectHash).openings--;
        if (getProject(projectHash).openings == 0) removeProject(projectHash);
        return;
    }
    throw std::runtime_error("No session found");
}
