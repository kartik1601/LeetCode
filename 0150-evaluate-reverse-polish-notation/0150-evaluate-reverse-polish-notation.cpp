class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string&str:tokens){
            if(str=="+" || str=="-" || str=="/" || str=="*"){
                int S=s.top(); s.pop();
                int F=s.top(); s.pop();
                if(str=="+"){
                    s.push(F+S);
                } else if(str=="-") {
                    s.push(F-S);
                } else if(str=="*") {
                    s.push(F*S);
                } else {
                    s.push(F/S);
                }
            } else {s.push(stoi(str));}
        }
        return s.top();
    }
};