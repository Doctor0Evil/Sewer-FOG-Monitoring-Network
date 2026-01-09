#pragma once

#include <cstdint>
#include <deque>

namespace sewerfog {

struct LevelSample {
    std::int64_t timestamp_unix_s;
    double level_m;
    double capacity_level_m;
};

struct OverflowPredictionConfig {
    std::size_t minSamples;
    double horizon_seconds;   // forecast horizon (e.g. 3600–21600)
};

struct OverflowPredictionResult {
    double probability;       // 0–1 probability of surcharge/overflow
    double projectedLevel_m;  // projected level at horizon
};

class OverflowPredictor {
public:
    explicit OverflowPredictor(const OverflowPredictionConfig &cfg);

    void addSample(const LevelSample &sample);
    OverflowPredictionResult predict() const;

private:
    OverflowPredictionConfig cfg_;
    std::deque<LevelSample> samples_;
};

} // namespace sewerfog
