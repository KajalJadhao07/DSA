class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_ele = *max_element(costs.begin(), costs.end());
        vector<int> count(max_ele + 1, 0);

        for(int x : costs) {
            count[x]++;
        }

        int idx = 0;

        for(int i = 0; i <= max_ele; i++) {
            while(count[i] > 0) {
                costs[idx++] = i;
                count[i]--;
            }
        }

        int cnt = 0;
        for(int i =0; i<costs.size(); i++){
            if(costs[i] <= coins){
                cnt++;
                coins -= costs[i];
            }else{
                break;
            }
        }

        return cnt;
    }
};