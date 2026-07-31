class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        
        for(char &ch:word) {
            freq[ch-'a']++;
        }

        sort(rbegin(freq),rend(freq));

        int res = 0;

        for(int i = 0; i < freq.size(); i++){
            res += freq[i] * (i / 8 + 1);
        }

        return res;
        
    }
};