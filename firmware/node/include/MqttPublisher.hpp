#pragma once

#include <string>
#include "SensorPacket.hpp"

class MqttPublisher {
public:
    MqttPublisher(const std::string &host, int port);

    bool connect();
    bool publish(const std::string &topic, const SensorPacket &packet);

private:
    std::string host_;
    int port_;
};
