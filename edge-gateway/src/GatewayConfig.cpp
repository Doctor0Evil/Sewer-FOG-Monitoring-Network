#include "GatewayConfig.hpp"
#include <cstdlib>

static std::string envOr(const char *k, const char *d) {
    if (const char *v = std::getenv(k)) return std::string(v);
    return std::string(d);
}

GatewayConfig GatewayConfig::fromEnv() {
    GatewayConfig cfg;
    cfg.udpListenPort = std::getenv("FOG_EDGE_UDP_PORT")
                      ? std::atoi(std::getenv("FOG_EDGE_UDP_PORT"))
                      : 9000;
    cfg.cloudMqttHost = envOr("FOG_EDGE_CLOUD_MQTT_HOST", "mqtt.example.com");
    cfg.cloudMqttPort = std::getenv("FOG_EDGE_CLOUD_MQTT_PORT")
                      ? std::atoi(std::getenv("FOG_EDGE_CLOUD_MQTT_PORT"))
                      : 8883;
    cfg.cloudMqttTopic = envOr("FOG_EDGE_CLOUD_MQTT_TOPIC", "sewerfog/ingest");
    return cfg;
}
