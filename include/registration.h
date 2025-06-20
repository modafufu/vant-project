#pragma once
#include <string>
#include "initialization.h"

struct RegistrationInfo {
    std::string user_id;
    std::string pubkey;
};

namespace registration {
    RegistrationInfo run(const SystemParams& params);
}