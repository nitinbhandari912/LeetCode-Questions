class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        while(n>0){
            int digit=n%10;
            if(digit!=0) x=x*10+digit;
            sum+=digit;
            n=n/10;
        }
        long long x1=0;
        while(x>0){
            int digit=x%10;
            x1=x1*10+digit;
            x=x/10;
        }
        return sum*x1;
    }
};