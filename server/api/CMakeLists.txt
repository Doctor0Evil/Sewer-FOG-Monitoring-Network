cmake_minimum_required(VERSION 3.16)

add_executable(fog_server_api
    src/main.cpp
    src/ApiConfig.cpp
    src/Database.cpp
    src/FogImpactService.cpp
    src/OverflowService.cpp
    src/IngestController.cpp
    src/QueryController.cpp
)

target_include_directories(fog_server_api PUBLIC include ../../src)
target_link_libraries(fog_server_api PUBLIC sewerfog_core pq)
