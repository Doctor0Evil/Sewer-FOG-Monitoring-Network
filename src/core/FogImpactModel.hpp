#pragma once

#include <cstdint>
#include <string>

namespace sewerfog {

struct FogNodeState {
    double cin_mg_per_L;   // inlet FOG concentration [mg/L]
    double cout_mg_per_L;  // outlet FOG concentration [mg/L]
    double flow_m3_per_s;  // volumetric flow rate [m^3/s]
    double dt_seconds;     // integration period [s]
};

struct FogImpactConfig {
    double cref_mg_per_L;     // reference concentration (e.g. local limit) [mg/L]
    double hazardWeight;      // dimensionless hazard weight w_FOG
    double karmaPerKg;        // Karma units per kg FOG avoided
};

struct FogImpactResult {
    double mFOG_kg;           // avoided FOG mass [kg] over dt
    double normalizedRisk;    // (Cin - Cout)/Cref (dimensionless)
    double karma;             // Karma units for the node over dt
};

FogImpactResult computeFogImpact(const FogNodeState &state,
                                 const FogImpactConfig &cfg);

} // namespace sewerfog
