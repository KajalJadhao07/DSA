class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> stk;
        int n = nums.size();

        if(k >= n){
            return "0";
        }

        for(int i =0; i< n; i++){
            while(!stk.empty() && k > 0 && stk.top()-'0' > nums[i]-'0'){
                stk.pop();
                k--;
            }
            stk.push(nums[i]);
        }

        while(k > 0){
            stk.pop();
            k--;
        }

        if(stk.empty()){
            return "0";
        }

        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }

        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if(res.empty()){
            return "0";
        }
        
        return res;
    }
};