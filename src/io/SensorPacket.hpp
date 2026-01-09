#pragma once

#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

namespace fog {

struct SensorPacket {
    std::string nodeId;
    std::int64_t timestamp_s;   // UNIX epoch seconds (UTC)
    double flow_m3s;            // hydraulic flow
    double fog_mgL;             // FOG concentration
    double temperature_C;
    double battery_V;
    std::uint32_t qualityFlags; // bitfield: sensor OK, comm OK, etc.

    nlohmann::json toJson() const {
        nlohmann::json j;
        j["node_id"]        = nodeId;
        j["timestamp_s"]    = timestamp_s;
        j["flow_m3s"]       = flow_m3s;
        j["fog_mgL"]        = fog_mgL;
        j["temperature_C"]  = temperature_C;
        j["battery_V"]      = battery_V;
        j["quality_flags"]  = qualityFlags;
        return j;
    }

    static SensorPacket fromJson(const nlohmann::json& j) {
        SensorPacket p;
        p.nodeId       = j.at("node_id").get<std::string>();
        p.timestamp_s  = j.at("timestamp_s").get<std::int64_t>();
        p.flow_m3s     = j.at("flow_m3s").get<double>();
        p.fog_mgL      = j.at("fog_mgL").get<double>();
        p.temperature_C= j.at("temperature_C").get<double>();
        p.battery_V    = j.at("battery_V").get<double>();
        p.qualityFlags = j.at("quality_flags").get<std::uint32_t>();
        return p;
    }
};

} // namespace fog
