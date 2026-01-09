#pragma once

#include "Database.hpp"
#include "FogImpactService.hpp"
#include "SensorPacket.hpp"

class IngestController {
public:
    IngestController(Database &db, const FogImpactService &impactSvc);

    void ingestJsonPacket(const std::string &json);

private:
    Database &db_;
    const FogImpactService &impactSvc_;
};
