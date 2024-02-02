class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string x = "123456789";
        vector<int> ans;
        for(int i=2 ; i<=9 ; i++){
            for(int j=0 ; j<=9-i ; j++){
                int temp = stoi(x.substr(j,i));
                if(temp>=low && temp<=high){ans.push_back(temp);}
            }
        }
        return ans;
    }
};