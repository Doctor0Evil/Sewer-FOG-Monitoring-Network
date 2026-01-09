#pragma once

#include <string>
#include <vector>

namespace sewerfog {

struct ReachStatus {
    std::string reachId;
    double riskScore;                   // 0–1 surcharge/overflow risk
    double dailyKarma;                  // Karma units for current day
    double deltaKarma24h;               // change over past 24h
    std::vector<std::string> topBasins; // suspected upstream FOG basins
};

class ChatAdapter {
public:
    static std::string makeReachSummary(const ReachStatus &status);
};

} // namespace sewerfog
