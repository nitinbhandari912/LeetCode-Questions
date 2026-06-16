class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        unordered_map<char,int> mpp;
        int cnt_even=0;
        bool has_odd = false;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            if(it.second/2>=1 && it.second%2!=0) {
                cnt_even+=it.second-1;
                has_odd = true;
            }
            else if(it.second%2==0) {
                cnt_even+=it.second;
            }
            else if(it.second == 1) {
                has_odd = true;
            }
        }
        if (has_odd) {
            return cnt_even + 1;
        }
        return cnt_even;
    }
};