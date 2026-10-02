#include <functional>

#pragma once

class EventBus {
public:
    template<typename Event>
    void publish(const Event& event);

    template<typename Event>
    void subscribe(std::function<void(const Event&)> handler);
};