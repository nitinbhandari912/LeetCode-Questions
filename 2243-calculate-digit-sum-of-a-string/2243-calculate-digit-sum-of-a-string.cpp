class Solution {
public:
    string digitSum(string s, int k) {
        string sum="";
        while(s.size()>k){
            int ss=0;
            int cnt=0;
            for(int i=0;i<s.size();i++){
                ss+=s[i]-'0';
                cnt++;
                if(cnt==k){
                    sum += to_string(ss);
                    ss=0;
                    cnt=0;
                }
            }
            if (cnt > 0) {                  
                sum += to_string(ss);
            }
            s=sum;
            sum.clear();
        }
        return s;
    }
};