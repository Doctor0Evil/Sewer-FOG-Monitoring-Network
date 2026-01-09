#include "ChatAdapter.hpp"
#include <sstream>
#include <iomanip>

namespace sewerfog {

std::string ChatAdapter::makeReachSummary(const ReachStatus &status) {
    std::ostringstream oss;
    oss << "Reach " << status.reachId << " is currently in the ";

    const double r = status.riskScore;
    std::string band;
    if (r < 0.2)      band = "low-risk band";
    else if (r < 0.5) band = "moderate-risk band";
    else if (r < 0.8) band = "high-risk band";
    else              band = "very high-risk band";

    oss << band << " with an estimated "
        << std::fixed << std::setprecision(0)
        << (r * 100.0) << "% overflow probability over the next few hours. ";

    oss << "Daily Karma for FOG reduction is approximately "
        << std::setprecision(1) << status.dailyKarma
        << " units, with a 24-hour change of "
        << (status.deltaKarma24h >= 0.0 ? "+" : "")
        << status.deltaKarma24h << " units. ";

    if (!status.topBasins.empty()) {
        oss << "Top suspected FOG contributors are: ";
        for (std::size_t i = 0; i < status.topBasins.size(); ++i) {
            oss << status.topBasins[i];
            if (i + 1 < status.topBasins.size()) {
                oss << ", ";
            } else {
                oss << ".";
            }
        }
    } else {
        oss << "No specific upstream FOG basins have been flagged in the current window.";
    }

    return oss.str();
}

} // namespace sewerfog
