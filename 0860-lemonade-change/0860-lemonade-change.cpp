class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntof5 = 0;
        int cntof10 = 0;
        int cntof20 = 0;

        for(int i =0; i<bills.size(); i++){
            if(bills[i] == 5){
                cntof5++;
            }else if(bills[i] == 10){
                if(cntof5 > 0){
                    cntof10++;
                    cntof5--;
                }else{
                    return false;
                }
            }else{
                if(cntof10 > 0 && cntof5 > 0){
                    cntof10--;
                    cntof5--;
                    cntof20++;
                }else if(cntof5 > 2){
                    cntof5 -= 3;
                    cntof20++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};