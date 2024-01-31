class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int> s;
        vector<int> res(n,0);
        s.push(n-1);
        for(int i=n-2 ; i>=0 ; i--){
            while(!s.empty() && t[i]>=t[s.top()]){s.pop();}
            if(!s.empty()){res[i] = s.top()-i;}
            s.push(i);
        }
        return res;
    }
};