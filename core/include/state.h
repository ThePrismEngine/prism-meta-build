#pragma once

#include <string>
#include "session.h"


namespace state {
    namespace config {
        void filename(SessionId sessionId, const std::string &filename);
        std::string& filename(SessionId sessionId);
    }

    namespace dslFiles {
        void nameSeparator(SessionId sessionId, const std::string &separator);
        std::string& nameSeparator(SessionId sessionId);
    }
}
