#include "ChatConfig.hpp"
#include <cstdlib>

static std::string envOr(const char *k, const char *d) {
    if (const char *v = std::getenv(k)) return std::string(v);
    return std::string(d);
}

ChatConfig ChatConfig::fromEnv() {
    ChatConfig cfg;
    cfg.listenAddress = envOr("FOG_CHAT_ADDR", "0.0.0.0");
    cfg.listenPort    = std::getenv("FOG_CHAT_PORT") ? std::atoi(std::getenv("FOG_CHAT_PORT")) : 9090;
    return cfg;
}
