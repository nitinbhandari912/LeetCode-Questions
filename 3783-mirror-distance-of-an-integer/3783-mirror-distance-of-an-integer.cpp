class Solution {
public:
    int mirrorDistance(int n) {
        int x=0;
        int temp=n;
        while(temp>0){
            int digit=temp%10;
            x=x*10+digit;
            temp=temp/10;
        }
        return abs(n-x);
    }
};