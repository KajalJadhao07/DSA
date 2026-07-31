class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>m;
        int n = word.size();

        for(int i =0; i<n; i++){
            m[word[i]]++;
        }
        
        vector<int> freq;

        for(auto it : m)
            freq.push_back(it.second);

        sort(freq.begin(), freq.end(), greater<int>());

        int res = 0;

        for(int i = 0; i < freq.size(); i++){
            res += freq[i] * (i / 8 + 1);
        }
        
        return res;
        
    }
};