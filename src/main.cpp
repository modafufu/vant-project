#include "zk_snark.h"
#include <iostream>

int main() {
    // 1. Setup 阶段
    PublicParams pp;
    pp.g = 2;
    pp.q = 104729; // 一个大素数
    pp.lambda = 4;

    int lambda;
    Poly R;
    setup(pp, lambda, R);
    std::cout << "Setup: lambda = " << lambda << ", R(x) = ";
    for (size_t i = 0; i < R.coeffs.size(); ++i) {
        std::cout << R.coeffs[i];
        if (i < R.coeffs.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    // 2. Prover 阶段
    mpz_class x0 = 42; // 车辆/节点的私有值
    mpz_class C;
    Proof proof;
    prover(lambda, R, x0, C, proof, pp);

    std::cout << "Prover: x0 = " << x0 << std::endl;
    std::cout << "Commitment C = " << C << std::endl;
    std::cout << "Proof π = " << proof.pi << std::endl;

    // 3. Verify 阶段
    bool ok = verify(C, proof, pp, R, x0);
    std::cout << "Verification Result: " << (ok ? "T (通过)" : "F (拒绝)") << std::endl;

    return 0;
}