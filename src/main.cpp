#include "../include/vanet.h"

int main() {
    // 1. 系统初始化
    SystemParams params;
    params.curve_name = "alt_bn128";
    params.security_param = 256;  // 256位安全性
    params.hash_algorithm = "SHA256";
    
    initialize_system(params);
    generate_global_parameters();
    
    // 2. 注册RSU和车辆
    register_entity("RSU", "RSU_001");
    register_entity("车辆", "Vehicle_001");
    
    return 0;
}