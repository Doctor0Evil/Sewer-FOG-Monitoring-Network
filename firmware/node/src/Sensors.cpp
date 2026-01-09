#include "Sensors.hpp"

// In production, wire to real ADCs, UARTs, or I2C for flow and FOG probes.

void Sensors::begin() {
    // Initialize hardware peripherals here.
}

SensorReadings Sensors::readOnce() {
    SensorReadings s{};
    // Placeholder simulated values; replace with real sensor drivers.
    s.flow_m3_per_s   = 0.008;
    s.fog_mg_per_L    = 200.0;
    s.temperature_C   = 25.0;
    s.battery_V       = 3.7;
    s.qualityFlags    = 0;
    return s;
}
