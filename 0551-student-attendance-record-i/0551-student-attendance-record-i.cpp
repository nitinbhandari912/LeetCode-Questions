class Solution {
public:
    bool checkRecord(string s) {
        int cntlate=0;
        int absentcnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A') absentcnt++;
            if(absentcnt>=2) return false;
            if(s[i]=='L'){
                cntlate++;
                if(cntlate>=3) return false;
            }
            else{
                cntlate=0;
            }
        }
        return true;
    }
};