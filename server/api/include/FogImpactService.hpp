#pragma once

#include "FogImpactModel.hpp"
#include "SensorPacket.hpp"

class FogImpactService {
public:
    explicit FogImpactService(const sewerfog::FogImpactConfig &cfg);

    sewerfog::FogImpactResult evaluate(const sewerfog::SensorPacket &packet,
                                       double dt_seconds) const;

private:
    sewerfog::FogImpactConfig cfg_;
};
