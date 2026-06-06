class Solution {
public:
    int arrangeCoins(int n) {
        int sum=n;
        int i=0;
        while(true){
            sum=sum-(i+1);
            i++;
            if(sum<0){
                break;
            }
        }
        return i-1;
    }
};