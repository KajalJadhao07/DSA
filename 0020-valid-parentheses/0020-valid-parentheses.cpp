class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }
            else {
                if(stk.empty()){
                    return false;
                }else if((ch == ')' && stk.top() == '(' ) || (ch == ']' && stk.top() == '[') || (ch == '}' && stk.top() == '{' )){
                    stk.pop();
                }else if((ch == ')' && stk.top() != '(' ) || (ch == ']' && stk.top() != '[') || (ch == '}' && stk.top() != '{' )){
                    return false;
                }
            }
        }

        return stk.empty();
    }
};