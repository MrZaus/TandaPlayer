
include(CTest)

list (APPEND ${CMAKE_PROJECT_NAME} "--output-on-failure;--schedule-random;--extra-verbose;--stop-on-failure;")

cmake_policy(SET CMP0135 NEW)

include(FetchContent)

FetchContent_Declare(
     googletest
     GIT_REPOSITORY "https://github.com/google/googletest"
     GIT_TAG        main
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

message(MZ: gtest_SOURCE_DIR  ${gtest_SOURCE_DIR})
# find_package(googletest REQUIRED)
file(GLOB TESTS_SRC
     "*_tests.cpp"
)
include(GoogleTest)

foreach(TEST_FILE ${TESTS_SRC})
     get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
     message(${TEST_FILE} ${TEST_NAME})
     add_executable(${TEST_NAME} ${TEST_FILE} )
     target_link_libraries(${TEST_NAME} PUBLIC playlist gtest_main)
     # add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
     gtest_discover_tests(${TEST_NAME})
endforeach()
