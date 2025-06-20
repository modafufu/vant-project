#include "session.h"
#include <iostream>

namespace session {
SessionResult run(const SystemParams&, const RegistrationInfo& reg) {
    std::cout << "会话阶段：生成承诺和零知识证明，User: " 
              << reg.user_id << ", Pubkey: " << reg.pubkey << std::endl;
    SessionResult result;
    result.proof = "zk_proof_example";
    result.commitment = "commitment_example";
    return result;
}
}