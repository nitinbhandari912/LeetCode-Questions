class Solution {
public:
    int addDigits(int num) {
        int sum=num;
        while(sum>=10){
            int n=sum;
            int evl=0;
            while(n>0){
                int digit=n%10;
                evl+=digit;
                n=n/10;
            }
            sum=evl;
        }
        return sum;
    }
};