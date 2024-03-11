class Solution {
public:
    string customSortString(string order, string s) {
        string res;
        int freq[26]={0};
        for(char&ch:s){freq[ch-'a']++;}
        for(char&ch:order){
            if(freq[ch-'a']>0){
                res.append(freq[ch - 'a'],ch);
                freq[ch-'a']=0;
            }
        }
        for(int i=0 ; i<26 ; i++){
            if(freq[i]>0){res.append(freq[i],i+'a');}
        }
        return res;
    }
};