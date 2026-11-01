#pragma once

#include "session.h"

Session& getSession(SessionId sessionId);
bool sessionExists(SessionId sessionId);