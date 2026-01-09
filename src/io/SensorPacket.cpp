#include "SensorPacket.hpp"
#include <sstream>
#include <stdexcept>

namespace sewerfog {

std::string SensorPacket::toJson() const {
    std::ostringstream oss;
    oss << "{"
        << "\"nodeId\":\"" << nodeId << "\","
        << "\"timestamp_unix_s\":" << timestamp_unix_s << ","
        << "\"flow_m3_per_s\":" << flow_m3_per_s << ","
        << "\"fog_mg_per_L\":" << fog_mg_per_L << ","
        << "\"temperature_C\":" << temperature_C << ","
        << "\"battery_V\":" << battery_V << ","
        << "\"qualityFlags\":" << qualityFlags
        << "}";
    return oss.str();
}

std::vector<std::uint8_t> SensorPacket::toMqttPayload() const {
    const auto json = toJson();
    return std::vector<std::uint8_t>(json.begin(), json.end());
}

SensorPacket SensorPacket::fromJson(const std::string &json) {
    // Minimal, robust JSON parser is recommended in production.
    // Here a placeholder throws to force callers to implement a real parser.
    throw std::runtime_error("SensorPacket::fromJson not implemented: use a JSON library in production");
}

} // namespace sewerfog
