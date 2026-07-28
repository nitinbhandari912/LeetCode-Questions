class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1) return s;
        int n=s.size();
        int half=n/2;
        string left_half = s.substr(0, half);
        sort(left_half.begin(),left_half.end());
        string right_half = left_half;
        reverse(right_half.begin(),right_half.end());
        if(n%2!=0){
            string mid(1, s[half]);
            return left_half + mid + right_half;
        }
        return left_half + right_half;
    }
};