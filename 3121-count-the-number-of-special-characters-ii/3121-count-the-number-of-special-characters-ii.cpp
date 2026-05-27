class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int cnt=0;
        vector<int> vec1(26,-1);
        vector<int> vec2(26,-1);
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(word[i]>='a' && word[i]<='z'){
                vec1[ch-'a']=i;
            }
            else if(word[i]>='A' && word[i]<='Z'){
                if(vec2[ch-'A']==-1){
                    vec2[ch-'A']=i;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(vec1[i]!=-1 && vec2[i]!=-1 && vec1[i]<vec2[i]) cnt++;
        }
        return cnt;
    }
};