class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        set<int> vis;
        queue<int> q;
        q.push(start);
        vis.insert(start);
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int idx=q.front(); q.pop();
                if(nums[idx]==0){return true;}
                int x=idx,y=nums[idx];
                if(x-y>=0 && vis.find(x-y)==vis.end()){
                    q.push(x-y); vis.insert(x-y);
                }
                if(x+y<nums.size() && vis.find(x+y)==vis.end()){
                    q.push(x+y); vis.insert(x+y);
                }
            }
        }
        
        return false;
    }
};