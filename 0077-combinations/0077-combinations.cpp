class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combo(k, 0);
        for (int i = 0; i < k; i++) {
            combo[i] = i + 1;
        }
        int i = 0;
        while (i >= 0) {
            result.push_back(combo);
            i = k - 1;
            while (i >= 0 && combo[i] == n - k + i + 1) {
                i--;
            }
            if (i >= 0) {
                combo[i]++;
                for (int j = i + 1; j < k; j++) {
                    combo[j] = combo[j - 1] + 1;
                }
            }
        }
        return result;
    }
};