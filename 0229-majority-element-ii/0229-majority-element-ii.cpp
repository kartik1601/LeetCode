class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,n1=0,n2=0,x=nums.size()/3;

        for(int num : nums){
            if(!c1 && num!=n2){n1=num; c1=1;}
            else if(!c2 && num!=n1){n2=num; c2=1;}
            else if(num==n1){c1++;}
            else if(num==n2){c2++;}
            else {c1--; c2--;}
        }

        vector<int> res;
        c1=0; c2=0;
        for(int num : nums){
            if(num==n1){c1++;}
            else if(num==n2){c2++;}
        }

        if(c1>x){res.push_back(n1);}
        if(c2>x){res.push_back(n2);}

        return res;
    }
};