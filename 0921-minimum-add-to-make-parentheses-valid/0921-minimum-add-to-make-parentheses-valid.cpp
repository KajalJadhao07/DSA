class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char> stk;

        for(char ch : s){
            if(ch == '('){
                stk.push(ch);
            }else{
                if(stk.empty()){
                    cnt++;
                }else{
                    stk.pop();
                }
            }
        }

        return cnt + stk.size();

    }
};