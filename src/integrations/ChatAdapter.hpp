#pragma once

#include <string>
#include <vector>

namespace fog {

struct ReachStatus {
    std::string reachId;
    double overflowRisk;      // 0–1
    double recentKarmaDelta;  // Karma/day
    std::vector<std::string> suspectedFogBasins;
};

inline std::string formatChatSummary(const ReachStatus& rs) {
    std::string txt;
    txt += "Reach " + rs.reachId + " is currently in ";
    if (rs.overflowRisk >= 0.8) {
        txt += "HIGH ";
    } else if (rs.overflowRisk >= 0.4) {
        txt += "MEDIUM ";
    } else {
        txt += "LOW ";
    }
    txt += "overflow risk band (probability ";
    txt += std::to_string(rs.overflowRisk);
    txt += " over the next few hours). ";

    txt += "Recent Karma change is ";
    txt += std::to_string(rs.recentKarmaDelta);
    txt += " units per day, reflecting FOG mass trends. ";

    if (!rs.suspectedFogBasins.empty()) {
        txt += "Top suspected high-FOG basins: ";
        for (std::size_t i = 0; i < rs.suspectedFogBasins.size(); ++i) {
            txt += rs.suspectedFogBasins[i];
            if (i + 1 < rs.suspectedFogBasins.size()) {
                txt += ", ";
            }
        }
        txt += ".";
    }
    return txt;
}

} // namespace fog
