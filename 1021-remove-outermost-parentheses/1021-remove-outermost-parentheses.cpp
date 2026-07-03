class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int cnt = 0;

        for(char ch : s){
            if(ch == '('){
                cnt++;
                if(cnt > 1){
                    res += '(';
                }
            }else{
                cnt--;
                if(cnt > 0){
                    res += ')';
                }
            }
        }
        return res;
    }
};