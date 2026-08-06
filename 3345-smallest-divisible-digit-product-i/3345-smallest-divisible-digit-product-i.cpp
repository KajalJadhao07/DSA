class Solution {
public:
    int get_multiply(int num){
        int res = 1;
        while(num > 0){
            int digit = num%10;
            res *= digit;
            num /= 10;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i< (n+11); i++){
            int multiplied = get_multiply(i);
            if(multiplied%t == 0){
                return i;
            }
        }
        return -1;
    }
};