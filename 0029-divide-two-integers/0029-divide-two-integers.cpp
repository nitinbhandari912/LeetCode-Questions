class Solution {
public:
    long long multiply(long long mid,long long absdivr){
        long long result = 0;
    while (mid > 0) {
        if (mid % 2 != 0) {
            result += absdivr;
        }
        absdivr *= 2; 
        mid /= 2;      
    }
    return result;
    }
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }
        bool negetive = (dividend<0)^(divisor<0);
        long long absdiv=abs((long long)dividend);
        long long absdivr=abs((long long)divisor);
        long long low = 0;
        long long high = absdiv;
        long long ans = 0;
        while(low<=high){
            long long mid=low + (high-low)/2;
            if(multiply(mid,absdivr)<=absdiv){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return negetive?-ans : ans;
    }
};