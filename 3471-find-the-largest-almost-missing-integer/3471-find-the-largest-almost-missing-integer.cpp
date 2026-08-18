class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        
        for(int i =0; i <= n-k; i++){
            unordered_set<int> s;
            for (int j = i; j < i + k; j++) {
                s.insert(nums[j]);
            }
            
            for (int x : s) {
                m[x]++;
            }
        }

        int largest = -1;
        
        for (auto it : m) {
            if (it.second == 1) {
                largest = max(largest, it.first);
            }
        }

        return largest;
    }
};