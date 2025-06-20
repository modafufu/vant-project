#include <iostream>
#include "initialization.h"
#include "registration.h"
#include "session.h"
#include "verification.h"

int main() {
    std::cout << "==== Initialization Phase ====" << std::endl;
    SystemParams sys_params = initialization::run();

    std::cout << "\n==== Registration Phase ====" << std::endl;
    RegistrationInfo reg_info = registration::run(sys_params);

    std::cout << "\n==== Session Phase ====" << std::endl;
    SessionResult session_result = session::run(sys_params, reg_info);

    std::cout << "\n==== Verification Phase ====" << std::endl;
    bool verified = verification::run(sys_params, reg_info, session_result);

    std::cout << "\n==== Verification Result: " << (verified ? "成功" : "失败") << " ====" << std::endl;
    return 0;
}