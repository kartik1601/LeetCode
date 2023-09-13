class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &p : freq){
            int num=p.first , times=p.second;
            pq.push({times,num});
            if(pq.size()>k) {pq.pop();}
        }
        
        while(!pq.empty())  {auto it = pq.top(); pq.pop(); ans.push_back(it.second);}
        
        return ans;
    }
};