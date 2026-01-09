#include "FogImpactService.hpp"

FogImpactService::FogImpactService(const sewerfog::FogImpactConfig &cfg)
    : cfg_(cfg) {}

sewerfog::FogImpactResult FogImpactService::evaluate(
    const sewerfog::SensorPacket &packet,
    double dt_seconds) const {

    sewerfog::FogNodeState state{};
    state.cin_mg_per_L  = packet.fog_mg_per_L;
    state.cout_mg_per_L = 0.0;
    state.flow_m3_per_s = packet.flow_m3_per_s;
    state.dt_seconds    = dt_seconds;

    return sewerfog::computeFogImpact(state, cfg_);
}
