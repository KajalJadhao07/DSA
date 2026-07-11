class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0;
        int r = 0;
        int cnt = 0;
        unordered_map<int, int> m;

        while(r < fruits.size()){
            m[fruits[r]]++;
            while(m.size() > 2){
                m[fruits[l]]--;
                if(m[fruits[l]] == 0){
                    m.erase(fruits[l]);
                }
                l++;
            }
            cnt = max(cnt, r-l+1);
            r++;
        }
        return cnt;
    }
};