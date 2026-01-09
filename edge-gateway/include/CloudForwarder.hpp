#pragma once

#include "SensorPacket.hpp"
#include <string>

class CloudForwarder {
public:
    CloudForwarder(const std::string &host, int port, const std::string &topic);
    bool connect();
    bool send(const sewerfog::SensorPacket &packet);

private:
    std::string host_;
    int port_;
    std::string topic_;
};
