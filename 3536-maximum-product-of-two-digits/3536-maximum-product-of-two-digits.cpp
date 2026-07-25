class Solution {
public:
    int maxProduct(int n) {
        int max_ele = 0;
        int sec_max_ele = 0;


        while(n > 0){
            int digit = n % 10;
            n /= 10;
            if(max_ele <= digit){
                sec_max_ele = max_ele;
                max_ele = digit; 
            }else if(sec_max_ele <= digit){
                sec_max_ele = digit;
            }
        }
        return max_ele * sec_max_ele;
    }
};