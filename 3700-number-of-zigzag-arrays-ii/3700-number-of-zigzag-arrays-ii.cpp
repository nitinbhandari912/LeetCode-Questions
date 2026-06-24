#include <vector>
#include <numeric>

class Solution {
private:
    int SIZE;
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& A, 
                                                 const std::vector<std::vector<long long>>& B) {
        std::vector<std::vector<long long>> C(SIZE, std::vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; ++i) {
            for (int k = 0; k < SIZE; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < SIZE; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    std::vector<std::vector<long long>> power(std::vector<std::vector<long long>> matrix, int p) {
        std::vector<std::vector<long long>> res(SIZE, std::vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, matrix);
            matrix = multiply(matrix, matrix);
            p >>= 1;
        }
        return res;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        int K = r - l + 1;
        if (n == 1) return K;
        SIZE = 2 * K;
        std::vector<std::vector<long long>> T(SIZE, std::vector<long long>(SIZE, 0));
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < i; ++j) {
                T[i][K + j] = 1;
            }
            for (int j = i + 1; j < K; ++j) {
                T[K + i][j] = 1;
            }
        }
        std::vector<std::vector<long long>> T_pow = power(T, n - 1);
        long long total_ways = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                total_ways = (total_ways + T_pow[i][j]) % MOD;
            }
        }
        return total_ways;
    }
};