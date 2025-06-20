#pragma once
#include <cstdint>

struct SystemParams {
    uint64_t g;
    uint64_t q;
    uint32_t lambda;
};

namespace initialization {
    SystemParams run();
}