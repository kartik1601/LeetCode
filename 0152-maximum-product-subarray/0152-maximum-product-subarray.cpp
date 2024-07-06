class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double currProd=1, maxProd=INT_MIN;

        for(int num:nums){
            currProd *= num;
            maxProd = max(maxProd,currProd);
            if(!currProd){currProd=1;}
        }

        currProd=1;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            currProd *= nums[i];
            maxProd = max(maxProd,currProd);
            if(!currProd){currProd=1;}
        }

        return maxProd;
    }
};