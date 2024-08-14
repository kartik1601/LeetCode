class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int k = tops.size();
        
        vector<int> t(7),b(7);
        for(int i=0 ; i<k ; i++){
            t[tops[i]]++; b[bottoms[i]]++;
        }

        int res=INT_MAX;

        for(int i=1 ; i<7 ; i++){
            if(t[i]+b[i]>=k){
                bool check = true;
                for(int j=0; j<k ; j++){
                    if(tops[j]!=i && bottoms[j]!=i){check=false; break;}
                }
                if(check){res = min(res,k-max(t[i],b[i]));}
            }
        }

        return res==INT_MAX ? -1 : res;
    }
};