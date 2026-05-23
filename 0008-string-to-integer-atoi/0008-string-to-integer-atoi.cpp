class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int sign=1;
        int result=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && ( s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            int digit=s[i]-'0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result=result*10+digit;
            i++;
        }
        return result*sign;
    }
};