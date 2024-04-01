class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0, ans=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]==' '){
                ans=len; len=0;
                while(s[i+1]==' ' && i<s.size()-1){i++;}
            }
            else{len++;}
        }
        return len==0 ? ans : len;
    }
};