#include "initialization.h"
#include <iostream>

namespace initialization {
SystemParams run() {
    std::cout << "初始化系统参数..." << std::endl;
    SystemParams params;
    params.g = 2;
    params.q = 104729;
    params.lambda = 4;
    return params;
}
}