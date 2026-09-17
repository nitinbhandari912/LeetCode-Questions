class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp; 
        int j = 0; 
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(s[i]) != mpp.end() && mpp[s[i]] >= j) {
                j = mpp[s[i]] + 1;
            } 
            mpp[s[i]] = i;
            maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};