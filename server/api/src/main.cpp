#include "ApiConfig.hpp"
#include "Database.hpp"
#include "FogImpactService.hpp"
#include "IngestController.hpp"
#include "QueryController.hpp"
#include <iostream>

int main() {
    ApiConfig cfg = ApiConfig::fromEnv();

    sewerfog::FogImpactConfig impactCfg{
        cfg.cref_mg_per_L,
        cfg.hazardWeight,
        cfg.karmaPerKg
    };

    Database db(cfg.dbConnString);
    if (!db.connect()) {
        return 1;
    }

    FogImpactService impactSvc(impactCfg);
    IngestController ingest(db, impactSvc);
    QueryController query(db);

    std::cout << "Server API listening on " << cfg.listenAddress << ":" << cfg.listenPort << "\n";
    std::cout << "Example reach summary: " << query.getReachSummary("PHX-FOG-REACH-01") << "\n";

    // In production, hook these controllers into a REST framework.
    for (;;) {}
}
