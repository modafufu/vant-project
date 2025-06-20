#pragma once
#include <string>
#include "initialization.h"
#include "registration.h"

struct SessionResult {
    std::string proof;
    std::string commitment;
};

namespace session {
    SessionResult run(const SystemParams& params, const RegistrationInfo& reg_info);
}