class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum == 0 && num > 1) return "";
        if (sum > 9 * num) return "";
        string n="";
        int cnt=0;
        for(int i=0;i<num;i++){
            if(sum<10){
                n+=to_string(sum);
                sum=0;
            }
            else if(sum==0){
                n+= '0';
            }
            else{
                n+='9';
                sum-=9;
            }
        }
        return n;
    }
};