class Solution {
public:
    string reverseWords(string s) {
        string rev="";
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                rev+=s[i];
            }
            else{
                reverse(rev.begin(),rev.end());
                ans+=rev+" ";
                rev="";
            }
        }
        reverse(rev.begin(),rev.end());
        ans+=rev;
        return ans;
    }
};