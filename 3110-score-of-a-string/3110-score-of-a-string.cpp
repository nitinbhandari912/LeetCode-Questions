class Solution {
public:
    int scoreOfString(string s) {
        int val=0;
        int i=0;
        int j=1;
        while(i< s.size() && j<s.size()){
            val+=abs((int)(s[i]-s[j]));
            i++;
            j++;
        }
        return val;
    }
};