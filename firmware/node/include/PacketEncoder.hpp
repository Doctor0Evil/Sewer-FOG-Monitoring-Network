#pragma once

#include "SensorPacket.hpp"
#include "NodeConfig.hpp"
#include "Sensors.hpp"

class PacketEncoder {
public:
    SensorPacket makePacket(const NodeConfig &cfg,
                            std::int64_t timestamp_unix_s,
                            const SensorReadings &s) const;
};
