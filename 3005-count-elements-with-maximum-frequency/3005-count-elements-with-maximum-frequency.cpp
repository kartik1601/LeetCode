class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        for(int num:nums){freq[num]++;}
        sort(freq,freq+101,[](int a,int b){return a>b;});
        
        int ans=1;
        for(int i=1; i<101; i++){
            if(freq[i]<freq[i-1]){break;}
            ans++;
        }
        return ans*freq[0];
    }
};