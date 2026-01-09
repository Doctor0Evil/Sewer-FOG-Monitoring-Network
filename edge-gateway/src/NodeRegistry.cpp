#include "NodeRegistry.hpp"

void NodeRegistry::update(const NodeInfo &info) {
    nodes_[info.nodeId] = info;
}

std::unordered_map<std::string, NodeInfo> NodeRegistry::snapshot() const {
    return nodes_;
}
