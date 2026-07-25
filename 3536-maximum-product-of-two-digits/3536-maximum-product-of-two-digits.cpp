class Solution {
public:
    int maxProduct(int n) {
        int maxi1=0;
        int maxi2=0;
        while(n>0){
            int digit=n%10;
            if(digit>maxi1){
                maxi2=maxi1;
                maxi1=digit;
            }
            else if(digit>maxi2){
                maxi2=digit;
            }
            n=n/10;
        }
        return maxi1*maxi2;
    }
};