#include "registration.h"
#include <iostream>

namespace registration {
RegistrationInfo run(const SystemParams&) {
    std::cout << "注册阶段：用户注册" << std::endl;
    RegistrationInfo info;
    info.user_id = "user123";
    info.pubkey = "pk_user123";
    return info;
}
}