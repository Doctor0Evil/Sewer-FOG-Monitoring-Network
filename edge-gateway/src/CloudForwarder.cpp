#include "CloudForwarder.hpp"
#include <iostream>

CloudForwarder::CloudForwarder(const std::string &host, int port, const std::string &topic)
    : host_(host), port_(port), topic_(topic) {}

bool CloudForwarder::connect() {
    std::cout << "Connecting gateway to cloud MQTT " << host_ << ":" << port_ << "\n";
    return true;
}

bool CloudForwarder::send(const sewerfog::SensorPacket &packet) {
    std::cout << "Forwarding packet for node " << packet.nodeId
              << " to topic " << topic_ << "\n";
    return true;
}
