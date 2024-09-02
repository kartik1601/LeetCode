class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = (int)chalk.size();
        vector<long long> pref(n,0);
        pref[0] = (long long)chalk[0];
        for(int i=1 ; i<n ; i++){pref[i] = pref[i-1]+chalk[i];}
        long long total = pref[n-1];

        if(k%total == 0){return 0;}
        if(total <  k){k -= (k/total)*total;}

        int res = (upper_bound(pref.begin(),pref.end(),k)-pref.begin())%n;
        return res;
    }
};