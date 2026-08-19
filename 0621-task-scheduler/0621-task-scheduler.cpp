class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        int t = tasks.size();
        for(auto ch : tasks) {
            freq[ch - 'A']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int idle = (freq[0] - 1) * n;

        for(int i = 1; i < freq.size(); i++) {
            idle -= min(freq[i], freq[0] - 1);
        }
        idle = max(0, idle);

        return t + idle;
    }
};