class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        rec("",n,n);
        return res;
    }
    void rec(string s,int op, int cl){
        if(!op && !cl){res.push_back(s); return;}

        if(op>0){rec(s+"(",op-1,cl);}
        if(cl>0 && cl!=op){rec(s+")",op,cl-1);}
    }
};