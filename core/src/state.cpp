#include "state.h"
#include "project_internal.h"


void state::config::filename(SessionId sessionId, const std::string &filename) {
    getProject(sessionId).state.config.filename = filename;
}

std::string& state::config::filename(const SessionId sessionId) {
    return getProject(sessionId).state.config.filename;
}


void state::dslFiles::nameSeparator(const SessionId sessionId, const std::string &separator) {
    getProject(sessionId).state.dslFiles.dslFilesSeparator = separator;
}

std::string& state::dslFiles::nameSeparator(const SessionId sessionId) {
    return getProject(sessionId).state.dslFiles.dslFilesSeparator;
}
