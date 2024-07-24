class Solution {
public:
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> newNums;

        for(int i=0 ; i<n ; i++){
            int num = nums[i], newNum = 0, p=1;
            if(!num){newNum = mp[0];}
            while(num){
                int r = num%10; num/=10;
                newNum += p*mp[r]; p*=10;
            }
            newNums.push_back({newNum,i});
        }

        sort(newNums.begin(),newNums.end(),[&](auto&p1,auto&p2){
            if(p1.first==p2.first){
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        });

        vector<int> res;
        for(auto&p : newNums){
            res.push_back(nums[p.second]);
        }

        return res;
    }
};