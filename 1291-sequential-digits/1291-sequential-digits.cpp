class Solution {
public:
    int get_digits(int num){
        if(num == 0) return 1;

        int digit_cnt = 0;
        while(num > 0){
            num/=10;
            digit_cnt++;
        }
        return digit_cnt;
    }

    vector<int> sequentialDigits(int low, int high) {
        int minDigits = get_digits(low);
        int maxDigits = get_digits(high);
        vector<int> ans;
        
        string s = "123456789";

        for(int len = minDigits; len <= maxDigits; len++) {
            for(int start = 0; start + len <= 9; start++) {

                string temp = s.substr(start, len);

                int num = stoi(temp);

                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};