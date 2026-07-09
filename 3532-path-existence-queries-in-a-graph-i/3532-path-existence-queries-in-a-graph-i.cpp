class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> answer;
        for(auto q : queries){
            int i=q[0];
            int j=q[1];
            if(abs(nums[i]-nums[j])<=maxDiff) answer.push_back(true);
            else if(i-j==1) answer.push_back(false);
            else{
                bool flag=true;
                if(i>j){
                    int temp=j;
                    j=i;
                    i=temp;
                }
                for(int k=i;k<j;k++){
                    if(abs(nums[k+1]-nums[k])<=maxDiff) continue;
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==true) answer.push_back(true);
                else answer.push_back(false);
            }
        }
        return answer;
    }
};