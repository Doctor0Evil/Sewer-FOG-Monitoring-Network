cmake_minimum_required(VERSION 3.16)

add_library(fog_node_firmware STATIC
    src/main.cpp
    src/Sensors.cpp
    src/MqttPublisher.cpp
    src/PacketEncoder.cpp
    src/NodeConfig.cpp
)

target_include_directories(fog_node_firmware PUBLIC include ../../src)
target_link_libraries(fog_node_firmware PUBLIC sewerfog_core)
