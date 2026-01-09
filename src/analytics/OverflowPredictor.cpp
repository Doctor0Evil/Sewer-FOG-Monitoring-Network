#include "OverflowPredictor.hpp"
#include <algorithm>

namespace sewerfog {

OverflowPredictor::OverflowPredictor(const OverflowPredictionConfig &cfg)
    : cfg_(cfg) {}

void OverflowPredictor::addSample(const LevelSample &sample) {
    samples_.push_back(sample);
    while (samples_.size() > 512) {
        samples_.pop_front();
    }
}

OverflowPredictionResult OverflowPredictor::predict() const {
    OverflowPredictionResult res{0.0, 0.0};
    if (samples_.size() < cfg_.minSamples) {
        return res;
    }

    const auto &first = samples_.front();
    const auto &last  = samples_.back();

    const double dt = static_cast<double>(last.timestamp_unix_s - first.timestamp_unix_s);
    if (dt <= 0.0) {
        res.projectedLevel_m = last.level_m;
        return res;
    }

    const double dLevel = last.level_m - first.level_m;
    const double slope = dLevel / dt;

    const double projected = last.level_m + slope * cfg_.horizon_seconds;
    res.projectedLevel_m = projected;

    if (last.capacity_level_m > 0.0) {
        const double frac = projected / last.capacity_level_m;
        res.probability = std::clamp(frac, 0.0, 1.0);
    }

    return res;
}

} // namespace sewerfog
