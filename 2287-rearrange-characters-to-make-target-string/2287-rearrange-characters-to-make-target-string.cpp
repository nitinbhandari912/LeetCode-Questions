class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> target_cnt(26, 0);
        vector<int> s_cnt(26, 0);
        for (char ch : target) target_cnt[ch - 'a']++;
        for (char ch : s)      s_cnt[ch - 'a']++;
        int mini = INT_MAX; 
        for (int i = 0; i < 26; i++) {
            if (target_cnt[i] > 0) {
                mini = min(mini, s_cnt[i] / target_cnt[i]);
            }
        }
        return mini;
    }
};