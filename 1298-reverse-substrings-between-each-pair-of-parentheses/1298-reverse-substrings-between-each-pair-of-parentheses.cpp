class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for (int i=0 ; i<s.size() ; i++) {
            if (s[i]=='(') {
                st.push(res.size());
            } else if (s[i]==')') {
                int opP = st.top(); st.pop();
                reverse(res.begin() + opP, res.end());
            } else {
                res+=s[i];
            }
        }
        return res;
    }
};