class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == ' '){
            i++;
        }

        if (i == n) {
            return 0;
        }

        bool pos = true;
        if(s[i] == '+'){
            i++;
        }else if(s[i] == '-'){
            pos = false;
            i++;
        }

        while (i < n && s[i] == '0')
            i++;

    
        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num*10 + (s[i]-'0');

            if(pos == true && num > INT_MAX){
                return INT_MAX;
            }

            if(pos == false && -num < INT_MIN){
                return INT_MIN;
            }
            i++;
        }

        if(pos == false){
            return -num;
        }
        return num;
    }
};