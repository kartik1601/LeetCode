class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int res = 0, prevMax = -v[0];

        for(int i=0 ; i<v.size() ; i++){
            res = max(res,v[i]-i+prevMax);
            prevMax = max(prevMax,v[i]+i);
        }

        return res;
    }
};