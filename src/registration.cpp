#include "../include/vanet.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <openssl/sha.h>

// 假设 alt_bn128_G1::generator() 返回生成元
extern alt_bn128_G1 g_generator;

// 生成密钥对
KeyPair generate_key_pair() {
    KeyPair kp;
    
    // 生成随机私钥
    kp.private_key = alt_bn128_Fr::random_element();
    
    // 计算公钥 (sk * G)
    kp.public_key = kp.private_key * g_generator;
    
    // 计算NodeID
    kp.node_id = compute_node_id(kp.public_key);
    
    return kp;
}

// 计算NodeID (SHA256哈希)
std::string compute_node_id(const alt_bn128_G1& public_key) {
    // 将公钥的 X 和 Y 坐标转换为字符串
    std::ostringstream oss;
    oss << "X: " << public_key.X << ", Y: " << public_key.Y;
    std::string pub_key_str = oss.str();
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, pub_key_str.c_str(), pub_key_str.size());
    SHA256_Final(hash, &sha256);
    
    // 将哈希转换为十六进制字符串
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ss.str();
}

// 注册实体(车辆或RSU)
void register_entity(const std::string& entity_type, const std::string& entity_id) {
    std::cout << "=== 注册" << entity_type << " ===" << std::endl;
    
    KeyPair keys = generate_key_pair();
    
    std::cout << entity_type << " ID: " << entity_id << std::endl;
    std::cout << "私钥: " << keys.private_key << std::endl;
    std::cout << "公钥: " << keys.public_key << std::endl;
    std::cout << "NodeID: " << keys.node_id << std::endl;
    std::cout << entity_type << " 注册成功!" << std::endl << std::endl;
}