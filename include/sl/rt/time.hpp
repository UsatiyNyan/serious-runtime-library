//
// Created by usatiynyan.
//

#pragma once

#include <sl/meta/lifetime/unique.hpp>

#include <chrono>
#include <utility>

namespace sl::rt {
using clock_type = std::chrono::steady_clock;

struct time_point {
    clock_type::time_point now;
    clock_type::duration delta_from_init;
    clock_type::duration delta;

    auto now_sec() const { return std::chrono::duration<float>{ now.time_since_epoch() }; }
    auto delta_from_init_sec() const { return std::chrono::duration<float>{ delta_from_init }; }
    auto delta_sec() const { return std::chrono::duration<float>{ delta }; }
};

class time : public meta::unique {
public:
    time_point calculate() {
        const auto now = clock_type::now();
        const auto delta_from_init = now - init_;
        const auto delta = now - std::exchange(now_, now);
        return time_point{ .now = now, .delta_from_init = delta_from_init, .delta = delta };
    };

private:
    std::chrono::steady_clock::time_point init_ = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point now_ = init_;
};

} // namespace sl::rt
