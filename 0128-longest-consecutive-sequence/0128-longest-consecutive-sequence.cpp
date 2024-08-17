class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),maxLen=1;
        if(!n){return 0;}
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());

        int cnt=0,prev=pq.top()-1;
        while(!pq.empty()){
            if(!pq.empty() && prev==pq.top()){pq.pop();}
            else if(!pq.empty() && prev+1 == pq.top()){
                prev = pq.top(); pq.pop();
                cnt++;
            } else {
                cnt=0; prev = pq.empty() ? 0 : pq.top()-1;
            }
            maxLen = max(maxLen,cnt);
        }

        return maxLen;
    }
};