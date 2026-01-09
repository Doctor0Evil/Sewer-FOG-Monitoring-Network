cmake_minimum_required(VERSION 3.16)
project(SewerFOGMonitoringNetwork LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_FIRMWARE_NODE "Build manhole node firmware" ON)
option(BUILD_EDGE_GATEWAY "Build edge gateway" ON)
option(BUILD_SERVER_API   "Build server API" ON)
option(BUILD_AI_CHAT      "Build AI chat integration" ON)

add_subdirectory(src)

if(BUILD_FIRMWARE_NODE)
  add_subdirectory(firmware/node)
endif()

if(BUILD_EDGE_GATEWAY)
  add_subdirectory(edge-gateway)
endif()

if(BUILD_SERVER_API)
  add_subdirectory(server/api)
endif()

if(BUILD_AI_CHAT)
  add_subdirectory(integrations/ai-chat)
endif()
