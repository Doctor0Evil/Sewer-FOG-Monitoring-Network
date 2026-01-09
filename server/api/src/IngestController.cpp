#include "IngestController.hpp"
#include <iostream>

IngestController::IngestController(Database &db, const FogImpactService &impactSvc)
    : db_(db), impactSvc_(impactSvc) {}

void IngestController::ingestJsonPacket(const std::string &json) {
    sewerfog::SensorPacket pkt = sewerfog::SensorPacket::fromJson(json);
    db_.storePacket(pkt);
    auto impact = impactSvc_.evaluate(pkt, 60.0);
    db_.storeImpact(pkt.nodeId, pkt.timestamp_unix_s, impact);
    std::cout << "Stored packet and impact for node " << pkt.nodeId << "\n";
}
