class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(), i=0, j=0, mod=1e9+7;
        long long sum1=0, sum2=0;

        while(i<n1 || j<n2){
            if(i<n1 && (j==n2 || nums1[i]<nums2[j])){
                sum1 += nums1[i++];
            } else if (j<n2 && (i==n1 || nums1[i]>nums2[j])) {
                sum2 += nums2[j++];
            } else {
                sum1 = max(sum1,sum2) + nums1[i];
                sum2 = sum1;
                i++; j++;
            }
        }

        return max(sum1,sum2) % mod;
    }
};