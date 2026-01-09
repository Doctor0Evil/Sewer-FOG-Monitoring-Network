cmake_minimum_required(VERSION 3.16)

add_executable(fog_ai_chat
    src/main.cpp
    src/ChatConfig.cpp
    src/ChatAdapter.cpp
    src/ChatServer.cpp
)

target_include_directories(fog_ai_chat PUBLIC include ../../src)
target_link_libraries(fog_ai_chat PUBLIC sewerfog_core)
