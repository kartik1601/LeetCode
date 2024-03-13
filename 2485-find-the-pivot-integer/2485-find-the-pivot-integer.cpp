class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i=1 ; i<=n ; i++){
            int sum1=i*(i+1)/2 , sum2=n*(n+1)/2-sum1+i;
            if(sum1==sum2){return i;}
        }
        return -1;
    }
};