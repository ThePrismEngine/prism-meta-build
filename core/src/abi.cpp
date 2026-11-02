#include <bit>

#include "abi.h"
#include "session_internal.h"
#include "error.h"
#include "project_internal.h"
#include "state.h"

PMB_EXTERN_C_BEGIN
pmb_session_t PMB_CALL pmb_session_new(const char* project_root) {
    return std::bit_cast<pmb_session_t>(newSession(std::string(project_root)));
};

void PMB_CALL pmb_session_delete(pmb_session_t session) {
    deleteSession(std::bit_cast<SessionId>(session));
}


void PMB_CALL pmb_error_call(pmb_session_t session, int type, const char* message) {
    callError(std::bit_cast<SessionId>(session), static_cast<ErrorType>(type), message);
}

pmb_error_t PMB_CALL pmb_error_get(pmb_session_t session) {
    Error error = getError(std::bit_cast<SessionId>(session));
    pmb_error_t abiError;
    abiError.message = error.message.c_str();
    abiError.type = error.type;
}


void PMB_CALL pmb_state_config_filename_set(pmb_session_t session, const char* filename) {
    state::config::filename(std::bit_cast<SessionId>(session), filename);
}

const char* PMB_CALL pmb_state_config_filename_get(pmb_session_t session) {
    return state::config::filename(std::bit_cast<SessionId>(session)).c_str();
}


void PMB_CALL pmb_state_dslFiles_separator_set(pmb_session_t session, const char* separator) {
    state::dslFiles::nameSeparator(std::bit_cast<SessionId>(session), separator);
}

const char* PMB_CALL pmb_state_dslFiles_separator_get(pmb_session_t session) {
    return state::dslFiles::nameSeparator(std::bit_cast<SessionId>(session)).c_str();
}

PMB_EXTERN_C_END