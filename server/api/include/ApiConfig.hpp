#pragma once

#include <string>

struct ApiConfig {
    std::string listenAddress;
    int listenPort;
    std::string dbConnString;
    double cref_mg_per_L;
    double hazardWeight;
    double karmaPerKg;

    static ApiConfig fromEnv();
};
