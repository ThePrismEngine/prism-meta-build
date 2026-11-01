set(MBS_CORE_SOURCES
        src/error.cpp
        src/session.cpp
        src/project.cpp
        src/state.cpp
)

set(MBS_CORE_HEADERS
        include/prism-mbs.h
        include/project_internal.h
        include/project.h
        include/session.h
        include/error.h
        include/state.h
        include/abi/project.h
)

add_library(mbs_core STATIC ${MBS_CORE_SOURCES} ${MBS_CORE_HEADERS})

target_include_directories(mbs_core
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_library(mbs::core ALIAS mbs_core)