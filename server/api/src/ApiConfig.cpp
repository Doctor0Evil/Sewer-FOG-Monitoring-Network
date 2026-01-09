#include "ApiConfig.hpp"
#include <cstdlib>

static std::string envOr(const char *k, const char *d) {
    if (const char *v = std::getenv(k)) return std::string(v);
    return std::string(d);
}

ApiConfig ApiConfig::fromEnv() {
    ApiConfig cfg;
    cfg.listenAddress = envOr("FOG_API_ADDR", "0.0.0.0");
    cfg.listenPort    = std::getenv("FOG_API_PORT") ? std::atoi(std::getenv("FOG_API_PORT")) : 8080;
    cfg.dbConnString  = envOr("FOG_DB_CONN", "host=localhost dbname=sewerfog user=sewerfog password=sewerfog");
    cfg.cref_mg_per_L = std::getenv("FOG_CREF_MG_L") ? std::atof(std::getenv("FOG_CREF_MG_L")) : 100.0;
    cfg.hazardWeight  = std::getenv("FOG_HAZARD_W") ? std::atof(std::getenv("FOG_HAZARD_W")) : 1.2;
    cfg.karmaPerKg    = std::getenv("FOG_KARMA_PER_KG") ? std::atof(std::getenv("FOG_KARMA_PER_KG")) : 0.75;
    return cfg;
}
