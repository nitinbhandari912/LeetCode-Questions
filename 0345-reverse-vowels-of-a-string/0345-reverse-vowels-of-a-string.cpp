class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vol;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vol.push_back(s[i]);
            }
        }
        reverse(vol.begin(),vol.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i]=vol[j];
                j++;
            }
        }
        return s;
    }
};