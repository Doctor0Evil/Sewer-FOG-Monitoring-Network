#pragma once

#include <string>
#include "SensorPacket.hpp"
#include "FogImpactModel.hpp"

struct PGconn;

class Database {
public:
    explicit Database(const std::string &connStr);
    ~Database();

    bool connect();
    void storePacket(const sewerfog::SensorPacket &packet);
    void storeImpact(const std::string &nodeId,
                     std::int64_t timestamp_s,
                     const sewerfog::FogImpactResult &impact);

private:
    std::string connStr_;
    PGconn *conn_;
};
