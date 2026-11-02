#pragma once

#include "abi_macros.h"
#include <stdint.h>

PMB_EXTERN_C_BEGIN

typedef uint64_t pmb_session_t;

#define PMB_ERR_WARNING  0
#define PMB_ERR_ERROR    1
#define PMB_ERR_CRITICAL 2

typedef struct {
    const char* message;
    int type;
} pmb_error_t;


PMB_API pmb_session_t PMB_CALL pmb_session_new(const char* project_root);
PMB_API void          PMB_CALL pmb_session_delete(pmb_session_t session);

PMB_API void        PMB_CALL pmb_error_call(pmb_session_t session, int type, const char* message);
PMB_API pmb_error_t PMB_CALL pmb_error_get(pmb_session_t session);

PMB_API void PMB_CALL        pmb_state_config_filename_set(pmb_session_t session, const char* filename);
PMB_API const char* PMB_CALL pmb_state_config_filename_get(pmb_session_t session);

PMB_API void PMB_CALL        pmb_state_dslFiles_separator_set(pmb_session_t session, const char* separator);
PMB_API const char* PMB_CALL pmb_state_dslFiles_separator_get(pmb_session_t session);

PMB_EXTERN_C_END