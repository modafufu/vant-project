#include "verification.h"
#include <iostream>

namespace verification {
bool run(const SystemParams&, const RegistrationInfo& reg, const SessionResult& session) {
    std::cout << "验证阶段：";
    std::cout << "User: " << reg.user_id 
              << ", Proof: " << session.proof 
              << ", Commitment: " << session.commitment << std::endl;
    // 实际应调用ZK验证算法，这里直接返回true
    return true;
}
}