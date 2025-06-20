#include "../include/vanet.h"
#include <stdexcept>

// 全局参数
alt_bn128_G1 g_generator;
std::vector<alt_bn128_Fr> g_poly_coeffs;

// 初始化系统参数
void initialize_system(const SystemParams& params) {
    try {
        // 初始化椭圆曲线参数
        alt_bn128_pp::init_public_params();
        
        // 设置生成器
        g_generator = alt_bn128_G1::one();
        
        std::cout << "=== 系统初始化 ===" << std::endl;
        std::cout << "曲线: " << params.curve_name << std::endl;
        std::cout << "安全参数: " << params.security_param << " bits" << std::endl;
        std::cout << "哈希算法: " << params.hash_algorithm << std::endl;
        std::cout << "生成器G: " << g_generator << std::endl;
        std::cout << "系统初始化成功!" << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "初始化失败: " << e.what() << std::endl;
        exit(1);
    }
}

// 生成全局参数
void generate_global_parameters() {
    const size_t poly_degree = 5; // 多项式次数
    
    std::cout << "=== 生成全局参数 ===" << std::endl;
    
    // 生成随机多项式系数
    for (size_t i = 0; i <= poly_degree; ++i) {
        alt_bn128_Fr coeff = alt_bn128_Fr::random_element();
        g_poly_coeffs.push_back(coeff);
        std::cout << "系数a_" << i << ": " << coeff << std::endl;
    }
    
    std::cout << "全局参数生成完成!" << std::endl << std::endl;
}