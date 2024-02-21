class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(!left || !right){return 0;}
        if(left==right){return left;}
        
        while(right>left){
            right &= (right-1);
        }
        return right;
    }
};