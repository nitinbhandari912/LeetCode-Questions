class Solution {
public:
    int maxDistinct(string s) {
        int cnt=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            cnt++;
        }
        return cnt;
    }
};