class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string&str:tokens){
            if(str=="+" || str=="-" || str=="/" || str=="*"){
                int S=s.top(); s.pop();
                int F=s.top(); s.pop();
                s.push(calc(F,S,str));
          
            } else {s.push(stoi(str));}
        }
        return s.top();
    }
    int calc(int x, int y, string op){
        if(op=="+"){
            return x+y;;
        } else if(op=="-") {
            return x-y;
        } else if(op=="*") {
            return x*y;
        }
        return x/y;
    }
};