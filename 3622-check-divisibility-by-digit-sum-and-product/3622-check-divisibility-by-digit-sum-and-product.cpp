class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int temp=n;
        while(temp>0){
            int digit=temp%10;
            temp=temp/10;
            sum+=digit;
            product*=digit;
        }
        if(n%(sum+product)==0) return true;
        return false;
    }
};