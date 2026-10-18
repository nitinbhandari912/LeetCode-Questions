class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<pair<int,int>,int>>arr(n) ;
        for(int i=0;i<n;i++){
            int sum=0;
            int temp=nums[i];
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            arr[i] = {{sum, nums[i]}, i};
        }
        sort(arr.begin(),arr.end());
        vector<bool> visited(n,false);
        int no_swap=0;
        for(int i=0;i<n;i++){
            if(visited[i] || arr[i].second==i){
                continue;
            }
            int cycle_size=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=arr[j].second;
                cycle_size++;
            }
            if (cycle_size > 0) {
                no_swap += (cycle_size - 1);
            }
        }
        return no_swap;
    }
};