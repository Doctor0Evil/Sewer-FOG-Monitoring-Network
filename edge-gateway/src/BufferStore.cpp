#include "BufferStore.hpp"

void BufferStore::push(const sewerfog::SensorPacket &pkt) {
    std::lock_guard<std::mutex> lk(m_);
    q_.push_back(pkt);
    while (q_.size() > 2048) q_.pop_front();
}

bool BufferStore::pop(sewerfog::SensorPacket &out) {
    std::lock_guard<std::mutex> lk(m_);
    if (q_.empty()) return false;
    out = q_.front();
    q_.pop_front();
    return true;
}
