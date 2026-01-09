#pragma once

#include <string>

class Database;

class QueryController {
public:
    explicit QueryController(Database &db) : db_(db) {}

    std::string getReachSummary(const std::string &reachId);

private:
    Database &db_;
};
