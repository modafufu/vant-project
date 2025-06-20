#include "../include/vanet.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <iostream>

// 会话密钥协商（ECDH）
SessionKey establish_session_key(const KeyPair& a_keys, const KeyPair& b_keys) {
    SessionKey sk;
    sk.party_a_id = a_keys.node_id;
    sk.party_b_id = b_keys.node_id;

    // ECDH: a方用自己私钥和b方公钥，b方也用自己私钥和a方公钥，得到相同的共享点
    sk.shared_point = a_keys.private_key * b_keys.public_key;

    // 可选：将椭圆曲线点（X，Y）哈希，获得对称密钥
    std::ostringstream oss;
    oss << sk.shared_point.X << sk.shared_point.Y;
    std::string point_str = oss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, point_str.c_str(), point_str.size());
    SHA256_Final(hash, &sha256);

    std::ostringstream hex_stream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hex_stream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    sk.session_key_hex = hex_stream.str();

    std::cout << "[SessionKey] 会话密钥协商完成，双方共享密钥: " << sk.session_key_hex << std::endl;
    return sk;
}