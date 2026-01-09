#include "Database.hpp"
#include <libpq-fe.h>
#include <iostream>

Database::Database(const std::string &connStr)
    : connStr_(connStr), conn_(nullptr) {}

Database::~Database() {
    if (conn_) {
        PQfinish(conn_);
    }
}

bool Database::connect() {
    conn_ = PQconnectdb(connStr_.c_str());
    if (PQstatus(conn_) != CONNECTION_OK) {
        std::cerr << "DB connection failed: " << PQerrorMessage(conn_) << "\n";
        return false;
    }
    return true;
}

void Database::storePacket(const sewerfog::SensorPacket &p) {
    if (!conn_) return;
    const std::string sql =
        "INSERT INTO fog_samples(node_id, ts, flow_m3s, fog_mgL, temperature_C, battery_V, quality_flags) "
        "VALUES($1, to_timestamp($2), $3, $4, $5, $6, $7)";
    const char *params[7];
    std::string ts = std::to_string(p.timestamp_unix_s);
    std::string flow = std::to_string(p.flow_m3_per_s);
    std::string fog = std::to_string(p.fog_mg_per_L);
    std::string temp = std::to_string(p.temperature_C);
    std::string batt = std::to_string(p.battery_V);
    std::string qf = std::to_string(p.qualityFlags);

    params[0] = p.nodeId.c_str();
    params[1] = ts.c_str();
    params[2] = flow.c_str();
    params[3] = fog.c_str();
    params[4] = temp.c_str();
    params[5] = batt.c_str();
    params[6] = qf.c_str();

    PGresult *res = PQexecParams(conn_, sql.c_str(), 7, nullptr, params, nullptr, nullptr, 0);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Insert sample failed: " << PQerrorMessage(conn_) << "\n";
    }
    PQclear(res);
}

void Database::storeImpact(const std::string &nodeId,
                           std::int64_t timestamp_s,
                           const sewerfog::FogImpactResult &impact) {
    if (!conn_) return;
    const std::string sql =
        "INSERT INTO fog_impact(node_id, ts, m_fog_kg, normalized_risk, karma) "
        "VALUES($1, to_timestamp($2), $3, $4, $5)";
    const char *params[5];
    std::string ts = std::to_string(timestamp_s);
    std::string m = std::to_string(impact.mFOG_kg);
    std::string r = std::to_string(impact.normalizedRisk);
    std::string k = std::to_string(impact.karma);

    params[0] = nodeId.c_str();
    params[1] = ts.c_str();
    params[2] = m.c_str();
    params[3] = r.c_str();
    params[4] = k.c_str();

    PGresult *res = PQexecParams(conn_, sql.c_str(), 5, nullptr, params, nullptr, nullptr, 0);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Insert impact failed: " << PQerrorMessage(conn_) << "\n";
    }
    PQclear(res);
}
