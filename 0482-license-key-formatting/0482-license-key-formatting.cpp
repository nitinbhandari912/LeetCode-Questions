class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string a="";
        string val="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='-'){
                val += toupper(s[i]);
            }
        }
        int cnt=0;
        for(int i=val.size()-1;i>=0;i--){
            if(cnt==k){
                a+='-';
                cnt=0;
            }
            
            a+=val[i];
            cnt++;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};