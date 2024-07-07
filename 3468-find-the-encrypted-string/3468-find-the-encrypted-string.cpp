class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string res;

        for(int i=0 ; i<n; i++){
            res += s[(i+k)%n];
        }

        return res;
    }
};