class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c : s){
            if(c== '1'){
                ones++;
            }
        }

        s = '1'+s+'1';

        int n = s.size();
        int i =0;

        int ans = ones;

        while(i < n && s[i]=='1'){
            i++;
        }

        int c_first0 = 0;

        while(i < n && s[i] == '0'){
            c_first0++;
            i++;
        }

        while(i < n){
            int c_ones = 0;
            while(i < n && s[i] == '1'){
                c_ones++;
                i++;
            }

            if(c_ones == 0){
                break;
            }

            int next_c2 = 0;
            while(i < n && s[i] == '0'){
                next_c2++;
                i++;
            }

            if(next_c2 == 0){
                break;
            }

            ans = max(ans, ones+ c_first0 + next_c2);
            c_first0 = next_c2;
        }
        return ans;
    }
};