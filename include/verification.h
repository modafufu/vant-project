#pragma once
#include "initialization.h"
#include "registration.h"
#include "session.h"

namespace verification {
    bool run(const SystemParams& params, const RegistrationInfo& reg, const SessionResult& session);
}