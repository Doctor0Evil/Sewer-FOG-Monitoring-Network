#include "FogImpactModel.hpp"
#include <algorithm>

namespace sewerfog {

FogImpactResult computeFogImpact(const FogNodeState &state,
                                 const FogImpactConfig &cfg) {
    FogImpactResult out{};

    const double dC_mg_per_L = std::max(0.0, state.cin_mg_per_L - state.cout_mg_per_L);

    // convert mg/L to kg/m^3 (1 mg/L = 0.001 kg/m^3)
    const double dC_kg_per_m3 = dC_mg_per_L * 0.001;

    // M_FOG = (Cin - Cout) * Q * t  in kg
    const double mFOG_kg = dC_kg_per_m3 * state.flow_m3_per_s * state.dt_seconds;

    double normalizedRisk = 0.0;
    if (cfg.cref_mg_per_L > 0.0) {
        normalizedRisk = dC_mg_per_L / cfg.cref_mg_per_L;
    }

    const double karma = cfg.hazardWeight * normalizedRisk * mFOG_kg * cfg.karmaPerKg;

    out.mFOG_kg = mFOG_kg;
    out.normalizedRisk = normalizedRisk;
    out.karma = karma;
    return out;
}

} // namespace sewerfog
