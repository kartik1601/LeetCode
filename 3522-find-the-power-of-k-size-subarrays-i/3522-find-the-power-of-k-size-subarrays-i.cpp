class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        // vector<int> maxEle(n);
        // maxEle[0] = nums[0];
        // for(int i=1 ; i<n ; i++){
        //     maxEle[i] = max(nums[i],maxEle[i-1]);
        // }

        for(int i=0 ; i<n-k+1 ; i++){
            bool chk=true;
            for(int j=i+1 ; j<i+k ; j++){
                if(!chk){break;}
                if(nums[j-1]+1!=nums[j]){
                    chk = false;
                } 
            }
            if(chk){res.push_back(nums[i+k-1]);}
            else{res.push_back(-1);}
        }

        return res;
    }
};