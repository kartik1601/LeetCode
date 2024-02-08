class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        for(int i=1; i<nums.size() ; i++){
            if(!st.empty() && nums[i]>=nums[st.top()]){st.push(i);}
        }
        return st.top();
    }
};