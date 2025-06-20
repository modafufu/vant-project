#include "zk_snark.h"
#include <ctime>

// Setup(pp) → (λ, R(x))
void setup(const PublicParams& pp, int& lambda, Poly& R) {
    lambda = pp.lambda;
    R.coeffs.resize(lambda);

    gmp_randclass rand_gen(gmp_randinit_default);
    rand_gen.seed(static_cast<unsigned long>(std::time(nullptr)));

    for (int i = 0; i < lambda; ++i) {
        R.coeffs[i] = rand_gen.get_z_range(pp.q);
    }
}

// p(x0) = R(x0)
mpz_class poly_eval(const Poly& R, const mpz_class& x, const mpz_class& q) {
    mpz_class res = 0;
    mpz_class xi = 1;
    for (auto& coeff : R.coeffs) {
        res = (res + coeff * xi) % q;
        xi = (xi * x) % q;
    }
    return res;
}

// Prover(λ, R(x), x0) → (C, π)
void prover(int lambda, const Poly& R, const mpz_class& x0, mpz_class& C, Proof& proof, const PublicParams& pp) {
    // 计算 p(x0)
    mpz_class px0 = poly_eval(R, x0, pp.q);

    // 承诺值 C = g^{p(x0)} mod q
    mpz_powm(C.get_mpz_t(), pp.g.get_mpz_t(), px0.get_mpz_t(), pp.q.get_mpz_t());

    // π 这里简单模拟为 p(x0) 的字符串（实际应为零知识证明）
    proof.pi = px0.get_str();
}

// Verify(C, π) → T / F
bool verify(const mpz_class& C, const Proof& proof, const PublicParams& pp, const Poly& R, const mpz_class& x0) {
    // 1. 计算 p(x0)
    mpz_class px0 = poly_eval(R, x0, pp.q);

    // 2. 计算 C' = g^{p(x0)} mod q
    mpz_class C_prime;
    mpz_powm(C_prime.get_mpz_t(), pp.g.get_mpz_t(), px0.get_mpz_t(), pp.q.get_mpz_t());

    // 3. if C != C' return false
    if (C != C_prime) return false;

    // 4. 验证 π（这里直接比对 p(x0) 字符串，实际应为ZK证明验证）
    std::string px0_str = px0.get_str();
    if (px0_str != proof.pi) return false;

    // 5. 通过
    return true;
}