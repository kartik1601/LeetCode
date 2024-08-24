class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MIN && b==-1){return INT_MAX;}
        int sign=1;
        if(a>0 ^ b>0){sign=-1;}
        long A = abs(a), B=abs(b), q=0;
        while(A>=B){
            long temp = B, m = 1;
            while(A >= temp<<1){
                temp <<= 1;
                m <<= 1;
            }
            A -= temp;
            q += m;
        }

        return sign*q;
    }
};