class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string r1="qQwWeErRTtYyuUiIoOpP";
        string r2="aAsSdDfFgGhHjJkKlL";
        string r3="zZxXcCvVbBnNmM";
        set<char> st1;
        set<char>st2;
        set<char>st3;
        for(int i=0;i<r1.size();i++){
            st1.insert(r1[i]);
        }
        for(int i=0;i<r2.size();i++){
            st2.insert(r2[i]);
        }
        for(int i=0;i<r3.size();i++){
            st3.insert(r3[i]);
        }
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int prev1=st1.size();
            int prev2=st2.size();
            int prev3=st3.size();
            set<char> temp1 = st1;
            for(int j=0;j<s.size();j++){
                temp1.insert(s[j]);
            }
            if(temp1.size()==prev1){
                ans.push_back(s);
                continue;
            }
            set<char> temp2 = st2;
            for(int j=0;j<s.size();j++){
                temp2.insert(s[j]);
            }
            if(temp2.size()==prev2){
                ans.push_back(s);
                continue;
            }
            set<char> temp3 = st3;
            for(int j=0;j<s.size();j++){
                temp3.insert(s[j]);
            }
            if(temp3.size()==prev3){
                ans.push_back(s);
                continue;
            }
        }
        return ans;
    }
};