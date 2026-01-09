#pragma once

#include "SensorPacket.hpp"
#include "BufferStore.hpp"
#include <thread>
#include <atomic>

class IngressServer {
public:
    explicit IngressServer(int listenPort, BufferStore &buffer);
    ~IngressServer();

    void start();
    void stop();

private:
    int port_;
    BufferStore &buffer_;
    std::thread thread_;
    std::atomic<bool> running_;
};
