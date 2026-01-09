#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace sewerfog {

struct SensorPacket {
    std::string nodeId;
    std::int64_t timestamp_unix_s;
    double flow_m3_per_s;
    double fog_mg_per_L;
    double temperature_C;
    double battery_V;
    std::uint32_t qualityFlags; // bitfield for QA/QC

    std::string toJson() const;
    std::vector<std::uint8_t> toMqttPayload() const;
    static SensorPacket fromJson(const std::string &json);
};

} // namespace sewerfog
