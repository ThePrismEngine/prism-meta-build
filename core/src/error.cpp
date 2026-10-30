#include "error.h"

static void callError(SessionId session, const ErrorType type, const std::string& message) {
    if (sessions.find(session) != sessions.end()) {
        sessions[session].errors.push(Error(message, type));
    } else {
        throw std::runtime_error(message);
    }

}

static Error getError(SessionId session) {
    if (sessions.find(session) != sessions.end()) {
        return sessions[session].errors.front();
    }
}

