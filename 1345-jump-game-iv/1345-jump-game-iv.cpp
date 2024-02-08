class Solution {
public:
    int minJumps(vector<int>&nums) {
        int ans=0, n=nums.size();
        set<int> vis;
        unordered_map<int,vector<int>> mp;
        queue<int> q;
        q.push(0); vis.insert(0);
        
        for(int i=0; i<n; i++){mp[nums[i]].push_back(i);}
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int idx=q.front(); q.pop();
                if(idx==n-1){return ans;}
                
                auto v = mp[nums[idx]];
                if(v.size()>1){
                    for(int j:v){if(j!=idx){q.push(j); vis.insert(j);}}
                }
                mp.erase(nums[idx]);
                if(idx>=1  && vis.find(idx-1)==vis.end()){q.push(idx-1); vis.insert(idx-1);}
                if(idx<n-1 && vis.find(idx+1)==vis.end()){q.push(idx+1); vis.insert(idx+1);}
            }
            ans++;
        }
        return n-1;
    }
};