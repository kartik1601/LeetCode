class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        int ans=0, n=c.size(), i=0 , curr=0;
        while(i<n-1){
            if(c[i]!=c[i+1]){
                if(curr==0){
                    curr=2;
                }
                else{
                    curr++;
                }
                if(curr==k){
                    ans++;
                    curr--;
                }
            }
            else{
                curr=0;
            }
            i++;
        }
        if(c[0]!=c[n-1]){
            if(curr==0){
                curr=2;
            }
            else{
                curr++;
            }
            if(curr==k){
                ans++;
                curr--;
            }
        }
        else{
            return ans;
        }

        for(int j=0;j<k-2;j++){
            if(c[j]!=c[j+1]){
                if(curr==0){
                    curr=2;
                }
                else{
                    curr++;
                }
                if(curr==k){
                    ans++;
                    curr--;
                }
            }
            else{
                break;
            }
        }
        return ans;
    }
};