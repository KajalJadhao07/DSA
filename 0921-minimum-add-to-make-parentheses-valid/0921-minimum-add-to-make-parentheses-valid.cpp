class Solution {
public:
    int minAddToMakeValid(string s) {
        int pos_cnt = 0;
        int moves = 0;

        for(char ch : s){
            if(ch == '('){
                pos_cnt++;
            }else{
                if(pos_cnt > 0){
                    pos_cnt--;
                }else{
                    moves++;
                }
            }
        }

        return pos_cnt + moves;

    }
};