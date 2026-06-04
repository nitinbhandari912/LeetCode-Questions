class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0;i<s.size();i++){
            if(m1[s[i]]==0 && m2[t[i]]==0){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else{
                if(m1[s[i]]==t[i] && m2[t[i]]==s[i]) continue;
                else return false;
            }
        }
        return true;
    }
};