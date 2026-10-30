#pragma once


#include <cstdint>
#include <map>
#include <queue>
#include <string>
#include <filesystem>

using ConnectionId = uint32_t;
using ProjectHash = uint32_t;

union SessionId {
    friend bool operator<(const SessionId &lhs, const SessionId &rhs) {
        return lhs.sessionId < rhs.sessionId;
    }

    friend bool operator<=(const SessionId &lhs, const SessionId &rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>(const SessionId &lhs, const SessionId &rhs) {
        return rhs < lhs;
    }

    friend bool operator>=(const SessionId &lhs, const SessionId &rhs) {
        return !(lhs < rhs);
    }

    friend bool operator==(const SessionId &lhs, const SessionId &rhs) {
        return lhs.sessionId == rhs.sessionId;
    }

    friend bool operator!=(const SessionId &lhs, const SessionId &rhs) {
        return !(lhs == rhs);
    }

    struct Parts {
        ProjectHash projectHash;
        ConnectionId connectionId;
    } parts;
    uint64_t sessionId;
};


enum ErrorType {
    ERROR_NOTICE,
    ERROR_WARNING,
    ERROR_CRITICAL
};

struct Error {
    Error(const std::string &message, ErrorType type) : message(message), type(type) {};

    std::string message;
    ErrorType type;
};

struct Session {
    std::queue<Error> errors;
};

std::map<SessionId, Session> sessions;

using Path = std::filesystem::path;

SessionId newSession(const Path& projectRoot);
void deleteSession(SessionId sessionId);