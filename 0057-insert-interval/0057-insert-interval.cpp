class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto&currInterval:intervals){
            if(currInterval[1]<newInterval[0]){
                ans.push_back(currInterval);
            } else if(newInterval[1]<currInterval[0]){
                ans.push_back(newInterval);
                newInterval=currInterval;
            } else{
                newInterval[0]=min(newInterval[0],currInterval[0]);
                newInterval[1]=max(newInterval[1],currInterval[1]);
            }    
        }
        ans.push_back(newInterval);
        return ans;
    }
};