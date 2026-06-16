class Solution {
public:
    string processStr(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                result+=s[i];
            }
            else if(s[i]=='*' && result.size()!=0){
                result.pop_back();
            }
            else if(s[i]=='#'){
                result+=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};