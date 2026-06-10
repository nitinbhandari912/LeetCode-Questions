class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int a=ans[ans.size()-1];
                int b=ans[ans.size()-2];
                ans.push_back(a+b);
            }
            else if(operations[i]=="C"){
                ans.pop_back();
            }
            else if(operations[i]=="D"){
                int num=ans[ans.size()-1];
                ans.push_back(2*num);
            }
            else{
                int n=stoi(operations[i]);
                ans.push_back(n);
            }
        }
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        return sum;
    }
};