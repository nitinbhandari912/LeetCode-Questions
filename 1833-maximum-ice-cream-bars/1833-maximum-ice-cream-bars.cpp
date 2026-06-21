class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins) {
                cnt++;
                coins-=costs[i];
            }
            else break;
        }
        return cnt;
    }
};