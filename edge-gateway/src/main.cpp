#include "GatewayConfig.hpp"
#include "BufferStore.hpp"
#include "IngressServer.hpp"
#include "CloudForwarder.hpp"
#include <chrono>
#include <thread>

int main() {
    GatewayConfig cfg = GatewayConfig::fromEnv();

    BufferStore buffer;
    IngressServer ingress(cfg.udpListenPort, buffer);
    ingress.start();

    CloudForwarder forwarder(cfg.cloudMqttHost, cfg.cloudMqttPort, cfg.cloudMqttTopic);
    forwarder.connect();

    while (true) {
        sewerfog::SensorPacket pkt;
        if (buffer.pop(pkt)) {
            forwarder.send(pkt);
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}
