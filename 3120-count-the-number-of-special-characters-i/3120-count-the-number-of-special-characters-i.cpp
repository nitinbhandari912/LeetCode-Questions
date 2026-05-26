class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        int n=word.size();
        set<char> q;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z') q.insert(word[i]);
        }
        for(auto it : q){
            for(int i=0;i<n;i++){
                if(it-'A'==word[i]-'a') {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};