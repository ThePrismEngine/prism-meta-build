#include "session.h"

#include <filesystem>
#include <random>

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
    sessions.insert({id, Session()});
};

void deleteSession(const SessionId sessionId) {
    sessions.erase(sessionId);
}