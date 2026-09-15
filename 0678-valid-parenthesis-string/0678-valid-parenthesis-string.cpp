class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;

        for(char ch = 0; ch < s.size(); ch++){
            if(s[ch] == '('){
                min++;
                max++;
            }else if(s[ch] == ')'){
                min--;
                max--;

            }else{
                min -= 1;
                max += 1;
            }


            if(min < 0){
                min = 0;
            }

            if(max < 0){
                return false;
            }
        }
        return ( min == 0);
    }
};