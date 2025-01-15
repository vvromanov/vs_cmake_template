set(TARGET vs_cmake_template_lib)
project(${TARGET})


add_library(${TARGET} STATIC
        src/vs_cmake_template_lib.cpp
        src/vs_cmake_template_lib.h
        )

target_include_directories(${TARGET} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

target_link_libraries(${TARGET}
        )

add_subdirectory(tests)
