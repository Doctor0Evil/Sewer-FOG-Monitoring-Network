#pragma once

#include <deque>
#include <cstddef>

namespace fog {

struct LevelSample {
    double t_s;        // time (s)
    double level_m;    // pipe level (m)
    double capacity_m; // crown level (m) or surcharge threshold
};

struct OverflowRisk {
    double horizon_s;  // forecast horizon
    double probability; // 0–1 probability of surcharge/overflow
};

class OverflowPredictor {
public:
    explicit OverflowPredictor(std::size_t maxSamples)
        : maxSamples_(maxSamples) {}

    void addSample(const LevelSample& s) {
        history_.push_back(s);
        if (history_.size() > maxSamples_) {
            history_.pop_front();
        }
    }

    OverflowRisk estimateRisk(double horizon_s) const {
        if (history_.size() < 2) {
            return {horizon_s, 0.0};
        }
        const LevelSample& first = history_.front();
        const LevelSample& last  = history_.back();
        const double dt = last.t_s - first.t_s;
        if (dt <= 0.0) {
            return {horizon_s, 0.0};
        }
        const double dLevel_dt = (last.level_m - first.level_m) / dt;

        const double remaining = last.capacity_m - last.level_m;
        if (remaining <= 0.0) {
            return {horizon_s, 1.0};
        }
        const double timeToCrown = remaining / std::max(dLevel_dt, 1e-9);

        double p = 0.0;
        if (timeToCrown <= 0.0) {
            p = 1.0;
        } else if (timeToCrown <= horizon_s) {
            p = (horizon_s - timeToCrown) / horizon_s;
            if (p < 0.0) p = 0.0;
            if (p > 1.0) p = 1.0;
        }
        return {horizon_s, p};
    }

private:
    std::size_t maxSamples_;
    std::deque<LevelSample> history_;
};

} // namespace fog
