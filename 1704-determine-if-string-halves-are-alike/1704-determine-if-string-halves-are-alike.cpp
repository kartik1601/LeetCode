class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(check(s[i])){
                i<n/2 ? cnt++ : cnt--;
            }
        }
        return cnt==0;
    }
    bool check(char &c){
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U'){
            return true;
        }
        return false;
    }
};