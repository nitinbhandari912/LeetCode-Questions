class Solution {
    public:
        char findChar(string& s,int i,long long k,const vector<long long>& lengths){
        if (i < 0 || k < 0) return '.'; 
        long long current_len = lengths[i];
        long long prev_len = (i == 0) ? 0 : lengths[i - 1];
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (k == current_len - 1) {
                return s[i]; 
            }
            return findChar(s, i - 1, k, lengths);
        }
        if (s[i] == '*') {
            return findChar(s, i - 1, k, lengths);
        }
        if (s[i] == '#') {
            if (k >= prev_len) {
                k %= prev_len;
            }
            return findChar(s, i - 1, k, lengths);
        }
        if (s[i] == '%') {
            k = current_len - 1 - k;
            return findChar(s, i - 1, k, lengths);
        }
        return '.';
    }
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lengths(n, 0);
        long long current_len = 0;
        long long MAX_K = 1e16;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*' && current_len > 0) {
                current_len--;
            } else if (s[i] == '#') {
                if (current_len > MAX_K) {
                    current_len = MAX_K;
                } else {
                    current_len *= 2;
                }
            } else if (s[i] == '%') {
            }
            lengths[i] = current_len;
        }
        if (k >= current_len || k < 0) {
            return '.';
        }
        if (k >= current_len || k < 0) {
            return '.';
        }
        return findChar(s, n - 1, k, lengths);
    }
};