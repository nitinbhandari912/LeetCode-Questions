class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        if(n==0) return 0;
        if(n==1) return cost[0];
        sort(cost.begin(),cost.end());
        int sum=0;
        int i=n-1;
        while(i>=0){
            sum+=cost[i];
            if(i-1>=0){
                sum+=cost[i-1];
            }
            i-=3;
        }
        return sum;
    }
};