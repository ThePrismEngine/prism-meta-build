set(MBS_CORE_SOURCES
        src/project.cpp
        src/error.cpp
        src/session.cpp
)

set(MBS_CORE_HEADERS
        include/prism-mbs.h
        include/project.h
        include/error.h
        include/session.h
        include/state.h
        src/state.cpp
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