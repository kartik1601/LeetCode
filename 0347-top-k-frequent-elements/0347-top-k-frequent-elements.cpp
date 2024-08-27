class Solution {
    using pii = pair<int,int>;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_map<int,int> freq;
        // n
        for(int idx=0; idx<n ; idx++){
            freq[nums[idx]]++;
        }

        vector<int> res;
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;
        
        // m * log(k) : m = no of unique elements
        for(auto p : freq){
            int num = p.first;
            int cnt = p.second;
            // log(k)
            if(minHeap.size()<k){
                minHeap.push({cnt,num});
            } else if(minHeap.top().first < cnt) {
                minHeap.pop();
                minHeap.push({cnt,num});
            }
        }

        // k * log(k)
        while(!minHeap.empty()){
            pair<int,int> p = minHeap.top(); minHeap.pop(); // log(k)
            res.push_back(p.second);
        }

        return res;
    }
};