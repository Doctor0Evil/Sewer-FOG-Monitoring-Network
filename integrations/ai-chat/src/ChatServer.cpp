#include "ChatServer.hpp"
#include <iostream>

ChatServer::ChatServer(const std::string &addr, int port)
    : addr_(addr), port_(port) {}

void ChatServer::run() {
    std::cout << "Chat webhook server listening on " << addr_ << ":" << port_ << "\n";

    sewerfog::ReachStatus status{
        "PHX-FOG-REACH-01",
        0.65,
        180.0,
        15.0,
        {"Downtown-Restaurant-Cluster", "Mixed-Use-Basin-02"}
    };
    std::string summary = sewerfog::ChatAdapter::makeReachSummary(status);
    std::cout << "Sample chat summary: " << summary << "\n";

    for (;;) {}
}
