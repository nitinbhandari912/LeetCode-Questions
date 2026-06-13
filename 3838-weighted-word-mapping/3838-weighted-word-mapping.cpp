class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string rev="";
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int sum=0;
            for(int j=0;j<s.size();j++){
                char ch=s[j];
                sum+=weights[ch-'a'];
            }
            int num=sum%26;
            char a = 'z' - num;
            rev+=a;
        }
        return rev;
    }
};