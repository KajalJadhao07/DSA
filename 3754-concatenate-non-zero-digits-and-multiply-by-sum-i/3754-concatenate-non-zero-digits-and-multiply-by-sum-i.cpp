class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        int sum = 0;
        string res = "";

        while(n > 0){
            int digit = n % 10;
            if(digit != 0){
                sum += digit;
                res += std::to_string(digit);
            }
            n /= 10;
        }

        if (res.empty()) {
            return 0; 
        }

        reverse(res.begin(), res.end());

        long long num = std::stoll(res); 
        
        return num * sum;
    }
};