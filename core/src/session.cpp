#include "session_internal.h"

#include <filesystem>
#include <random>


namespace {
    std::map<SessionId, Session>& getSessionsMap() {
        static std::map<SessionId, Session> sessions;
        return sessions;
    }
}

Session& getSession(const SessionId sessionId) {
    getSessionsMap().at(sessionId);
}

bool sessionExists(const SessionId sessionId) {
    return getSessionsMap().contains(sessionId);
}

static ConnectionId generateConnectionId() {
    thread_local std::random_device rd;
    thread_local std::mt19937 gen(rd());

    static std::uniform_int_distribution<uint32_t> distrib(
        std::numeric_limits<uint32_t>::min(),
        std::numeric_limits<uint32_t>::max()
    );

    return distrib(gen);
}

SessionId newSession(const Path& projectRoot) {
    SessionId id;
    id.parts.projectHash = hash_value(projectRoot);
    id.parts.connectionId = generateConnectionId();
    getSessionsMap().insert({id, Session()});
};

void deleteSession(const SessionId sessionId) {
    getSessionsMap().erase(sessionId);
}