#include "ChatConfig.hpp"
#include "ChatServer.hpp"

int main() {
    ChatConfig cfg = ChatConfig::fromEnv();
    ChatServer server(cfg.listenAddress, cfg.listenPort);
    server.run();
}
