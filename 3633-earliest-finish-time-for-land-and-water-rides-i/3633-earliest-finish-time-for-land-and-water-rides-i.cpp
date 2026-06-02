class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int sum=INT_MAX;
        for(int i=0;i<n;i++){
            int m=waterStartTime.size();
            int tempsum=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                if(tempsum>=waterStartTime[j]){
                    sum=min(sum,tempsum+waterDuration[j]);
                }
                else{
                    sum=min(sum,waterDuration[j]+waterStartTime[j]);
                }
            }
        }
        int m=waterStartTime.size();
        int sum1=INT_MAX;
        for(int i=0;i<m;i++){
            int tempsum=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                if(tempsum>=landStartTime[j]){
                    sum1=min(sum1,tempsum+landDuration[j]);
                }
                else{
                    sum=min(sum,landDuration[j]+landStartTime[j]);
                }
            }
        }
        return min(sum,sum1);
    }
};