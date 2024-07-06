class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& cl, int k) {
        int n = cl.size();
        vector<int> c;
        for(int i=0 ; i<n+k-1 ; i++){
            c.push_back(cl[i%n]);
        }

        int currWindow=1, cnt=0;

        for(int i=0 ; i<n+k-2 ; i++){
            if(c[i]==c[i+1]){
                currWindow = 1;
            } else {
                currWindow++;
            }
            if(currWindow==k){
                cnt++;
                currWindow--;
            }
        }

        return cnt;
    }
};