cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(TARGET vs_cmake_template)
project (${TARGET})
enable_language(C)
enable_language(CXX)

enable_testing()
#add_custom_target(check)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    add_compile_options(-W)
    add_compile_options(-Wall)
    add_compile_options(-Werror)
    add_compile_options(-Wpointer-arith)
    add_compile_options(-Wformat-security)
    add_compile_options(-Woverloaded-virtual)
    add_compile_options(-Wwrite-strings)
    add_compile_options(-fvisibility=hidden)
    add_compile_options(-Wunused-parameter -Wunused-function -Wunused-variable -Wunused-value -Wmissing-declarations)
    add_compile_options(-Wmissing-field-initializers)
    add_compile_options(-Wcast-qual)
    add_compile_options(-ggdb)

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-O0)
        add_compile_options(-g3)
        add_compile_options(-fsanitize=address)
        add_link_options(-fsanitize=address)
        add_compile_options(-fsanitize=undefined)
        add_link_options(-fsanitize=undefined)
    endif()
    if (CMAKE_BUILD_TYPE STREQUAL "Relase")
        add_compile_options(-O3)
        add_compile_options(-g3)
    endif()
    if (COVERAGE)
        if (NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
            message(FATAL_ERROR "Coverage requires -DCMAKE_BUILD_TYPE=Debug Current value=${CMAKE_BUILD_TYPE}")
        endif ()

        message(STATUS "Setting coverage compiler flags")

        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb3 -O0 --coverage -fprofile-arcs -ftest-coverage")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}     -g -ggdb3 -O0 --coverage -fprofile-arcs -ftest-coverage")

        add_definitions(-DCOVERAGE_TEST)
    endif (COVERAGE)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    # Enable Hot Reload for MSVC compilers if supported.
    if (POLICY CMP0141)
      cmake_policy(SET CMP0141 NEW)
      set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
    endif()
    add_compile_options(/W3)
    add_compile_options(/Zi)
    if (CMAKE_BUILD_TYPE STREQUAL "Relase")
        add_compile_options(/Ot)
    endif()
endif()

add_subdirectory(lib)

# Add source to this project's executable.
add_executable (${TARGET} 
	src/vs_cmake_template.cpp 
	)

target_link_libraries(${TARGET}
        vs_cmake_template_lib
        )

# TODO: Add tests and install targets if needed.
