set(TARGET vs_cmake_template_lib_test)
project(${TARGET})

enable_testing()
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(${TARGET}
    vs_cmake_template_test.cpp
)

target_link_libraries(
    ${TARGET} PRIVATE 
    GTest::gtest
    GTest::gtest_main
#    GTest::gmock
#    GTest::gmock_main
    vs_cmake_template_lib
)

target_compile_features(${TARGET} PRIVATE cxx_std_20)

gtest_discover_tests(
    ${TARGET}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    XML_OUTPUT_DIR gtest-reports
    DISCOVERY_MODE PRE_TEST
)
