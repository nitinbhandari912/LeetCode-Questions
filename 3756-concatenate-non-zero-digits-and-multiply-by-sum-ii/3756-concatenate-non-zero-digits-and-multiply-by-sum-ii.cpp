class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(); 
        int MOD = 1e9 + 7;
        vector<long long> pow10(n + 1, 1);
        vector<int> sumD(n + 1, 0);
        vector<int> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        for (int i = 0; i < n; i++) pow10[i + 1] = (pow10[i] * 10) % MOD;
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0 ? 1 : 0);
            p[i] = (d > 0) ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }
        vector<int> answer;
        for (const auto& it : queries) {
            int L = it[0];
            int R = it[1];
            int n0 = cntN0[R + 1] - cntN0[L];
            int sd = sumD[R + 1] - sumD[L];
            long long x = (p[R + 1] - (p[L] * pow10[n0]) % MOD + MOD) % MOD;
            answer.push_back((int)((x * sd) % MOD));
        }
        return answer;
    }
};