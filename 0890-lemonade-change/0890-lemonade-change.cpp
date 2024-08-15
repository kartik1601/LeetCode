class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change = 0, five=0,ten=0;
        for(int bill : bills){
            change += bill;
            if (bill==5){
                five++;
            } else if (bill==10){
                ten++;
                if(five>0){five--;}
                else {return false;}
            } else if (bill==20){
                if(five>0 && ten>0){five--; ten--;}
                else if (five>=3) {five-=3;}
                else {return false;}
            }
        }
        return true;
    }
};