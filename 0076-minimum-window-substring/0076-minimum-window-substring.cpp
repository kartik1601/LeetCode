class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        int left = 0;
        int idx = -1;
        int len = INT_MAX;
        
        if(n<m) {return "";}
        
        unordered_map<char, int> m1, m2;
        
        for(char&c:t){m2[c]++;}
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            m1[ch]++;
            if(m1[ch] <= m2[ch]) {count++;}
            
            if(count == m) { 
                char temp = s[left];
                while(m1[temp] > m2[temp] || m2[temp] == 0 ) {
                    if(m1[temp] > m2[temp])
                        m1[temp]--;
                    left++;
                    temp = s[left];
                }
                
                if(i-left+1 < len ) {
                    len = i-left+1;
                    idx = left;
                }
            }
        }
        
        if(idx==-1){return "";}
        
        return s.substr(idx, len);
    }
};