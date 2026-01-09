#include "IngressServer.hpp"
#include <iostream>
#include <chrono>

IngressServer::IngressServer(int listenPort, BufferStore &buffer)
    : port_(listenPort), buffer_(buffer), running_(false) {}

IngressServer::~IngressServer() {
    stop();
}

void IngressServer::start() {
    running_ = true;
    thread_ = std::thread([this]() {
        std::cout << "IngressServer listening on UDP port " << port_ << "\n";
        while (running_) {
            // In production, read UDP packets and decode SensorPacket.
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
}

void IngressServer::stop() {
    running_ = false;
    if (thread_.joinable()) thread_.join();
}
