#pragma once
#include <gmpxx.h>
#include <vector>
#include <string>

// 公共参数结构体
struct PublicParams {
    mpz_class g, q;
    int lambda;
};

// 随机多项式
struct Poly {
    std::vector<mpz_class> coeffs;
};

// 证明结构体
struct Proof {
    std::string pi; // 这里只做演示，实际应填入ZK证明内容
};

// Setup(pp) → (λ, R(x))
void setup(const PublicParams& pp, int& lambda, Poly& R);

// Prover(λ, R(x), x0) → (C, π)
void prover(int lambda, const Poly& R, const mpz_class& x0, mpz_class& C, Proof& proof, const PublicParams& pp);

// Verify(C, π) → T / F
bool verify(const mpz_class& C, const Proof& proof, const PublicParams& pp, const Poly& R, const mpz_class& x0);