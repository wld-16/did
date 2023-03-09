cmake_minimum_required(VERSION 3.17)
project(did-pvote)

set(nlohmann_json_DIR ~/json-3.10.4/build)
set(CMAKE_CXX_STANDARD 20)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(nlohmann_json 3.11.0 REQUIRED)

set(SOURCE_FILES
        src/didPVoteResolver.h
        src/didPVoteResolver.cpp
        src/did.h
        src/didDocument.cpp
        src/didDocument.h)

add_executable(did_pvote_app  ${SOURCE_FILES})
#add_executable(did_test ${IDENTITY_SRC_FILES})
add_library(did_pvote SHARED ${SOURCE_FILES})

#target_link_libraries(identity_test)
target_link_libraries(did_pvote_app PRIVATE nlohmann_json::nlohmann_json Threads::Threads)
target_link_libraries(did_pvote PRIVATE nlohmann_json::nlohmann_json Threads::Threads)