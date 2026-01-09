#include "QueryController.hpp"
#include <sstream>

std::string QueryController::getReachSummary(const std::string &reachId) {
    // In production, query fog_impact table and aggregate.
    std::ostringstream oss;
    oss << "{"
        << "\"reachId\":\"" << reachId << "\","
        << "\"riskScore\":0.5,"
        << "\"dailyKarma\":180.0"
        << "}";
    return oss.str();
}
