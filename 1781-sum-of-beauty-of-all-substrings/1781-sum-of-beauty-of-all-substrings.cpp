class Solution {
public:
    int beautySum(string s) {
        int total = 0;

        for(int i =0; i<s.size()-1; i++){
            vector<int>alpha(26, 0);
            for(int j = i; j<s.size(); j++){
                alpha[s[j]-'a']++;
                int min_value = INT_MAX;
                int max_value = 0;
                for(int k =0; k <26; k++){
                    max_value = max(max_value, alpha[k]);
                    if(alpha[k] >= 1){
                        min_value = min(min_value, alpha[k]);
                    }
                }
                total += max_value-min_value;
            }
        }
        return total;
    }
};