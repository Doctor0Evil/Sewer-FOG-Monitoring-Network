#include "MqttPublisher.hpp"
#include <iostream>

MqttPublisher::MqttPublisher(const std::string &host, int port)
    : host_(host), port_(port) {}

bool MqttPublisher::connect() {
    // In production, use a real MQTT client (e.g. Paho).
    std::cout << "Connecting to MQTT broker " << host_ << ":" << port_ << "\n";
    return true;
}

bool MqttPublisher::publish(const std::string &topic, const SensorPacket &packet) {
    const auto payload = packet.toJson();
    std::cout << "MQTT publish to " << topic << " payload=" << payload << "\n";
    return true;
}
