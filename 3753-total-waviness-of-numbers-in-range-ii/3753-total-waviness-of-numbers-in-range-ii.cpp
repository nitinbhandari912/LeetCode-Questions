#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    long long countUpTo(long long N) {
        if (N < 100) return 0;
        string s = to_string(N);
        int len = s.length();
        long long total_waviness = 0;
            for (int L = 3; L < len; ++L) {
            vector<vector<long long>> ways(10, vector<long long>(10, 0));
            vector<vector<long long>> wave(10, vector<long long>(10, 0));
            for (int d1 = 1; d1 <= 9; ++d1) {
                for (int d2 = 0; d2 <= 9; ++d2) {
                    ways[d2][d1] = 1;
                }
            }
            for (int i = 2; i < L; ++i) {
                vector<vector<long long>> next_ways(10, vector<long long>(10, 0));
                vector<vector<long long>> next_wave(10, vector<long long>(10, 0));
                for (int p1 = 0; p1 <= 9; ++p1) {
                    for (int p2 = 0; p2 <= 9; ++p2) {
                        if (ways[p1][p2] == 0) continue;
                        for (int d = 0; d <= 9; ++d) {
                            int is_wave = ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) ? 1 : 0;
                            next_ways[d][p1] += ways[p1][p2];
                            next_wave[d][p1] += wave[p1][p2] + (is_wave * ways[p1][p2]);
                        }
                    }
                }
                ways = next_ways;
                wave = next_wave;
            }
            for (int p1 = 0; p1 <= 9; ++p1) {
                for (int p2 = 0; p2 <= 9; ++p2) {
                    total_waviness += wave[p1][p2];
                }
            }
        }
        vector<vector<long long>> free_ways(10, vector<long long>(10, 0));
        vector<vector<long long>> free_wave(10, vector<long long>(10, 0));
        int first_d1 = s[0] - '0';
        int first_d2 = s[1] - '0';
        long long tight_wave = 0; 
        long long tight_p1 = first_d2, tight_p2 = first_d1;
        for (int d1 = 1; d1 <= 9; ++d1) {
            for (int d2 = 0; d2 <= 9; ++d2) {
                if (d1 < first_d1 || (d1 == first_d1 && d2 < first_d2)) {
                    free_ways[d2][d1] = 1;
                }
            }
        }
        for (int i = 2; i < len; ++i) {
            vector<vector<long long>> next_free_ways(10, vector<long long>(10, 0));
            vector<vector<long long>> next_free_wave(10, vector<long long>(10, 0));
            int limit_digit = s[i] - '0';
            for (int p1 = 0; p1 <= 9; ++p1) {
                for (int p2 = 0; p2 <= 9; ++p2) {
                    if (free_ways[p1][p2] == 0) continue;
                    for (int d = 0; d <= 9; ++d) {
                        int is_wave = ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) ? 1 : 0;
                        next_free_ways[d][p1] += free_ways[p1][p2];
                        next_free_wave[d][p1] += free_wave[p1][p2] + (is_wave * free_ways[p1][p2]);
                    }
                }
            }
            for (int d = 0; d < limit_digit; ++d) {
                int is_wave = ((tight_p1 > tight_p2 && tight_p1 > d) || (tight_p1 < tight_p2 && tight_p1 < d)) ? 1 : 0;
                next_free_ways[d][tight_p1] += 1;
                next_free_wave[d][tight_p1] += tight_wave + is_wave;
            }
            int tight_is_wave = ((tight_p1 > tight_p2 && tight_p1 > limit_digit) || (tight_p1 < tight_p2 && tight_p1 < limit_digit)) ? 1 : 0;
            tight_wave += tight_is_wave;
            tight_p2 = tight_p1;
            tight_p1 = limit_digit;
            free_ways = next_free_ways;
            free_wave = next_free_wave;
        }
        for (int p1 = 0; p1 <= 9; ++p1) {
            for (int p2 = 0; p2 <= 9; ++p2) {
                total_waviness += free_wave[p1][p2];
            }
        }
        total_waviness += tight_wave;
        return total_waviness;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return countUpTo(num2) - countUpTo(num1 - 1);
    }
};