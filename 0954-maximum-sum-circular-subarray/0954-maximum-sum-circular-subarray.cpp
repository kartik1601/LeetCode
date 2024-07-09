class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),sum=0;

        int currSumMin=0, minSum=INT_MAX, currSumMax=0, maxSum=INT_MIN;
        for(int num : nums){
            currSumMin = min(currSumMin+num,num);
            minSum = min(minSum,currSumMin);

            currSumMax = max(currSumMax+num,num);
            maxSum = max(maxSum,currSumMax);
            
            sum += num;
        }
        
        if(sum==minSum){return maxSum;}
        return max(maxSum,sum-minSum);
    }
};