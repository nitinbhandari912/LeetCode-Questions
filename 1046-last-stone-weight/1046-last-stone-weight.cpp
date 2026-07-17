class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        int n=stones.size();
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());
            int i = stones.size() - 1;
            int l1 = stones[i];
            int l2 = stones[i-1];
            if(l1==l2){
                stones.pop_back();
                stones.pop_back();
                i-=2;
            }
            else {
                stones[i-1] = l1 - l2;
                stones.pop_back();
                i-=1;
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};