#pragma once

#include <string>

struct GatewayConfig {
    int udpListenPort;
    std::string cloudMqttHost;
    int cloudMqttPort;
    std::string cloudMqttTopic;

    static GatewayConfig fromEnv();
};
