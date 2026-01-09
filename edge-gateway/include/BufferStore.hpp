#pragma once

#include <deque>
#include <mutex>
#include "SensorPacket.hpp"

class BufferStore {
public:
    void push(const sewerfog::SensorPacket &pkt);
    bool pop(sewerfog::SensorPacket &out);

private:
    std::deque<sewerfog::SensorPacket> q_;
    std::mutex m_;
};
