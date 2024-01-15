class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> a1,a2;
        unordered_map<int,int> freq;
        for(auto&match : matches){
            freq[match[1]]++; 
            if(freq.find(match[0])==freq.end()){freq[match[0]]=0;}
        }
        
        for(auto& [x,c] : freq){
            if(c<=0){a1.push_back(x);}
            if(c==1){a2.push_back(x);}
        }
        
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        return {a1,a2};
    }
};