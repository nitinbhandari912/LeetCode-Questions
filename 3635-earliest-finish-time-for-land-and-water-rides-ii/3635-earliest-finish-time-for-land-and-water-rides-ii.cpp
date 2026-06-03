class Solution {
public:
    int solve(vector<int>& landStartTime,vector<int>& landDuration,vector<int>&waterStartTime,vector<int>& waterDuration){
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int finish1=INT_MAX;
        for(int i=0;i<n;i++){
            finish1=min(finish1,landStartTime[i]+landDuration[i]);
        }
        int finish2=INT_MAX;
        for(int i=0;i<m;i++){
            finish2=min(finish2,max(finish1,waterStartTime[i])+waterDuration[i]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};