#pragma once

#include <string>

struct ChatConfig {
    std::string listenAddress;
    int listenPort;

    static ChatConfig fromEnv();
};
