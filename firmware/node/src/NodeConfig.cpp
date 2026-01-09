#include "NodeConfig.hpp"
#include <cstdlib>

static std::string envOr(const char *key, const char *fallback) {
    if (const char *v = std::getenv(key)) return std::string(v);
    return std::string(fallback);
}

NodeConfig NodeConfig::fromEnv() {
    NodeConfig cfg;
    cfg.nodeId  = envOr("FOG_NODE_ID", "PHX-FOG-REACH-01");
    cfg.mqttBrokerHost = envOr("FOG_MQTT_HOST", "192.168.1.10");
    cfg.mqttBrokerPort = std::getenv("FOG_MQTT_PORT")
                       ? std::atoi(std::getenv("FOG_MQTT_PORT"))
                       : 1883;
    cfg.mqttTopic = envOr("FOG_MQTT_TOPIC", "sewerfog/nodes");
    cfg.samplePeriodSeconds = std::getenv("FOG_SAMPLE_PERIOD_S")
                            ? std::atof(std::getenv("FOG_SAMPLE_PERIOD_S"))
                            : 60.0;
    return cfg;
}
