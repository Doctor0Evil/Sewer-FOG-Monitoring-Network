#pragma once

#include <string>

struct NodeConfig {
    std::string nodeId;
    std::string mqttBrokerHost;
    int         mqttBrokerPort;
    std::string mqttTopic;
    double      samplePeriodSeconds;

    static NodeConfig fromEnv();
};
