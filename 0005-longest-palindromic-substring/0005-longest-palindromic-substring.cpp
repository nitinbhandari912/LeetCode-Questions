class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        vector<pair<string, pair<int, int>>> vec;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    string charStr(1, s[i]); 
                    vec.push_back({charStr, {i, j}});
                }
            }
        }

        int max_len = 0;
        string a = "";

        for (int i = 0; i < vec.size(); i++) {
            int j = vec[i].second.first;
            int k = vec[i].second.second;
            
            int q = j;
            int z = k;
            bool isPalindrome = true;
            while (q <= z) {
                if (s[q] != s[z]) {
                    isPalindrome = false;
                    break; 
                }
                q++;
                z--;
            }
            if (isPalindrome) {
                int current_len = k - j + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                    a = s.substr(j, current_len); 
                }
            }
        }
        return a;
    }
};