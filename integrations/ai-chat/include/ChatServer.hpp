#pragma once

#include "ChatAdapter.hpp"
#include <string>

class ChatServer {
public:
    ChatServer(const std::string &addr, int port);

    void run();

private:
    std::string addr_;
    int port_;
};
