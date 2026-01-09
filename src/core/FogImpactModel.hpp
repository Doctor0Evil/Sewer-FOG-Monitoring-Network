#pragma once

#include <stdexcept>

namespace fog {

struct FogNodeState {
    double Cin_mgL;   // upstream FOG, mg/L
    double Cout_mgL;  // downstream FOG, mg/L
    double Q_m3s;     // flow, m^3/s
    double dt_s;      // integration window, s
};

struct FogImpactConfig {
    double Cref_mgL;      // reference limit, e.g. 100 mg/L
    double hazardWeight;  // w_FOG, dimensionless
    double karmaPerKg;    // Karma per kg FOG avoided
};

struct FogImpactResult {
    double massAvoided_kg;
    double nodeImpact_K;
};

inline FogImpactResult computeFogImpact(const FogNodeState& s,
                                        const FogImpactConfig& cfg) {
    if (cfg.Cref_mgL <= 0.0) {
        throw std::invalid_argument("Cref_mgL must be positive.");
    }
    if (s.dt_s <= 0.0 || s.Q_m3s <= 0.0) {
    return {0.0, 0.0};
    }
    const double deltaC_mgL = s.Cin_mgL - s.Cout_mgL;
    if (deltaC_mgL <= 0.0) {
        return {0.0, 0.0};
    }
    const double Cin_kgm3  = s.Cin_mgL  * 1.0e-6;
    const double Cout_kgm3 = s.Cout_mgL * 1.0e-6;
    const double deltaC_kgm3 = Cin_kgm3 - Cout_kgm3;

    const double mass_kg = deltaC_kgm3 * s.Q_m3s * s.dt_s;

    const double riskUnit = deltaC_mgL / cfg.Cref_mgL;

    const double K = cfg.hazardWeight * riskUnit * mass_kg * cfg.karmaPerKg;

    return {mass_kg, K};
}

} // namespace fog
