cmake_minimum_required(VERSION 3.16)

add_executable(fog_edge_gateway
    src/main.cpp
    src/GatewayConfig.cpp
    src/NodeRegistry.cpp
    src/IngressServer.cpp
    src/CloudForwarder.cpp
    src/BufferStore.cpp
)

target_include_directories(fog_edge_gateway PUBLIC include ../../src)
target_link_libraries(fog_edge_gateway PUBLIC sewerfog_core)
