#ifndef VANET_H
#define VANET_H

#include <libsnark/common/default_types/r1cs_ppzksnark_pp.hpp>
#include <libff/algebra/curves/alt_bn128/alt_bn128_pp.hpp>
#include <openssl/sha.h>
#include <string>
#include <vector>
#include <iostream>

// 使用libsnark和libff的命名空间
using namespace libsnark;
using namespace libff;

// 系统参数结构体
struct SystemParams {
    std::string curve_name;
    size_t security_param;
    std::string hash_algorithm;
};

// 密钥对结构体
struct KeyPair {
    alt_bn128_Fr private_key;
    alt_bn128_G1 public_key;
    std::string node_id;
};

// 初始化函数声明
void initialize_system(const SystemParams& params);
void generate_global_parameters();

// 注册函数声明
KeyPair generate_key_pair();
std::string compute_node_id(const alt_bn128_G1& public_key);
void register_entity(const std::string& entity_type, const std::string& entity_id);



struct SessionKey {
    std::string party_a_id;
    std::string party_b_id;
    alt_bn128_G1 shared_point;      // 椭圆曲线上的共享点
    std::string session_key_hex;    // 哈希后的会话密钥
};

// 会话密钥协商接口
SessionKey establish_session_key(const KeyPair& a_keys, const KeyPair& b_keys);


#endif // VANET_H