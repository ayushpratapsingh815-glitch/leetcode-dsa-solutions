class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five  = 0;
        int ten = 0;
        for(int num : bills) {
            if(num == 5) {
                five++;
            } else if(num == 10) {
                if(five > 0) {
                    ten++;
                    five--;
                } else {
                    return false;
                }
            } else if(num == 20) {
                if(five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if(five >= 3) {
                    five--;
                    five--;
                    five--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};