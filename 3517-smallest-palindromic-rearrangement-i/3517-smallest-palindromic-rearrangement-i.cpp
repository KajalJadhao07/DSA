class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> m;
        string res = "";

        for(char ch : s){
            m[ch]++;
        }

        string mid = "";

        for(auto it : m){
            if(it.second % 2 != 0){
                mid = string(1, it.first); 
            }
            res.append(it.second / 2, it.first);
        }

        string copy_res = res;
        reverse(copy_res.begin(), copy_res.end());

        return res+mid+copy_res;
    }
};