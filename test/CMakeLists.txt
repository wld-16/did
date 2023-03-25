cmake_minimum_required(VERSION 3.17)

set(SOURCE_FILES
        testDid.cpp
)

set(name test_did)

add_executable(${name} ${SOURCE_FILES})

target_link_libraries(${name} PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main
        did_lib
        )

add_test(
        NAME ${name}
        COMMAND ${name}
)
