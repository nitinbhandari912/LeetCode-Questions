class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n=list1.size();
        int m=list2.size();
        int sum=INT_MAX;
        vector<string> ans;
        for(int i=0;i<n;i++){
            string s=list1[i];
            for(int j=0;j<m;j++){
                if (list1[i] == list2[j]) {
                    int current_sum = i + j;
                    if(current_sum<sum){
                        sum=current_sum;
                        ans.clear();
                        ans.push_back(s);
                    }
                    else if(current_sum==sum){
                        ans.push_back(s);
                    }
                }
            }
        }
        return ans;
    }
};