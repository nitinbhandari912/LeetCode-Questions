class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt=0;
        int a=0;
        int i=0;
        while(a<s.size() && i<t.size()){
            if(s[a]==t[i]) {
                cnt++;
                a++;
            }
            i++;
        }
        if(cnt==s.size()) return true;
        else return false;
    }
};