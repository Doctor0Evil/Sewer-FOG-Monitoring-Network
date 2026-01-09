#pragma once

#include <cstdint>

struct SensorReadings {
    double flow_m3_per_s;
    double fog_mg_per_L;
    double temperature_C;
    double battery_V;
    std::uint32_t qualityFlags;
};

class Sensors {
public:
    void begin();
    SensorReadings readOnce();
};
