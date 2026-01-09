#include "PacketEncoder.hpp"

SensorPacket PacketEncoder::makePacket(const NodeConfig &cfg,
                                       std::int64_t timestamp_unix_s,
                                       const SensorReadings &s) const {
    SensorPacket pkt;
    pkt.nodeId            = cfg.nodeId;
    pkt.timestamp_unix_s  = timestamp_unix_s;
    pkt.flow_m3_per_s     = s.flow_m3_per_s;
    pkt.fog_mg_per_L      = s.fog_mg_per_L;
    pkt.temperature_C     = s.temperature_C;
    pkt.battery_V         = s.battery_V;
    pkt.qualityFlags      = s.qualityFlags;
    return pkt;
}
