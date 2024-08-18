class Solution {
public:
    int nthUglyNumber(int n) {
        int k=n;
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(1);
        
        while(k>1){
            int val = pq.top(); pq.pop(); k--;
            if((long long)val*2 <= INT_MAX && !mp.count(val*2)){
                pq.push(val*2); mp[val*2]=1;
            }
            if((long long)val*3 <= INT_MAX && !mp.count(val*3)){
                pq.push(val*3); mp[val*3]=1;
            }
            if((long long)val*5 <= INT_MAX && !mp.count(val*5)){
                pq.push(val*5); mp[val*5]=1;
            }
        }

        return pq.top();
    }
};