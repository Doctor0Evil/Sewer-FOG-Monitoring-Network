#pragma once

#include <string>
#include <unordered_map>
#include <cstdint>

struct NodeInfo {
    std::string nodeId;
    std::int64_t lastSeen_unix_s;
};

class NodeRegistry {
public:
    void update(const NodeInfo &info);
    std::unordered_map<std::string, NodeInfo> snapshot() const;

private:
    std::unordered_map<std::string, NodeInfo> nodes_;
};
