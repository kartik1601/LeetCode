class Solution {
public:
    int minOperations(vector<string>& logs) {
        int op=0;

        for(auto&log:logs){
            if(log=="../"){
                if(op>0){op--;}
            } else if (log=="./"){
                // op = op;
            } else {
                op++;
            }
        }

        return op;
    }
};