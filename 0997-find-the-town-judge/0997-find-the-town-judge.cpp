class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int freq[1001] = {0};
        for(auto&v:trust){
            freq[v[1]]++; freq[v[0]]--;
        }
        for(int x=1;x<1001; x++){if(freq[x]==n-1){return x;}}
        return -1;
    }
};