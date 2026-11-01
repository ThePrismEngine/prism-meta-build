#pragma once

#include <string>
#include "session.h"


void callError(SessionId session, const ErrorType type, const std::string& message);
Error getError(SessionId session);