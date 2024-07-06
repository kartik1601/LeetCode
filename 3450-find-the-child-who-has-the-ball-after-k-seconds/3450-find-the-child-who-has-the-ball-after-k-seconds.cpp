class Solution {
public:
    int numberOfChild(int n, int k) {
        if((k/(n-1))%2==0){return k%(n-1);}
        return (n-1)-(k%(n-1));
    }
};