#include "NodeConfig.hpp"
#include "Sensors.hpp"
#include "PacketEncoder.hpp"
#include "MqttPublisher.hpp"
#include <chrono>
#include <thread>
#include <ctime>

static std::int64_t now_unix_s() {
    return static_cast<std::int64_t>(std::time(nullptr));
}

int main() {
    NodeConfig cfg = NodeConfig::fromEnv();

    Sensors sensors;
    sensors.begin();

    MqttPublisher publisher(cfg.mqttBrokerHost, cfg.mqttBrokerPort);
    if (!publisher.connect()) {
        return 1;
    }

    PacketEncoder encoder;

    while (true) {
        const auto t = now_unix_s();
        const auto readings = sensors.readOnce();
        auto packet = encoder.makePacket(cfg, t, readings);
        publisher.publish(cfg.mqttTopic, packet);
        std::this_thread::sleep_for(
            std::chrono::milliseconds(static_cast<int>(cfg.samplePeriodSeconds * 1000)));
    }
}
