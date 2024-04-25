//
// Created by usatiynyan.
//

#pragma once

#include <filesystem>
#include <span>
#include <string_view>

namespace sl::rt {

struct context {
    constexpr context(int argc, char** argv) : args{ argv, static_cast<std::size_t>(argc) }, name{ args[0] } {}

    auto path() const { return std::filesystem::path{ name }; }

public:
    std::span<char*> args;
    std::string_view name;
};


} // namespace sl::rt
