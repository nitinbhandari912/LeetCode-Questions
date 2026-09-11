class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (int d : digits)
            cnt[d]++;
        int res = 0;
        for (int a = 1; a <= 9; a++) {
            if (cnt[a] == 0)
                continue;
            cnt[a]--;
            for (int b = 0; b <= 9; b++) {
                if (cnt[b] == 0)
                    continue;
                cnt[b]--;
                for (int c = 0; c <= 8; c += 2) {
                    if (cnt[c] > 0)
                       res++;
                }
                cnt[b]++;
            }
            cnt[a]++;
        }
        return res;
    }
};