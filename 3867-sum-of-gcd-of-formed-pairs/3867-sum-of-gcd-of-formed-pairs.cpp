class Solution {
public:
    int get_gcd(int num1, int num2){
        if(num2 == 0){
            return num1;
        }
        return get_gcd(num2, num1 % num2);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> ps(nums.size(), 0);
        vector<int>gcd(nums.size());

        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                ps[i] = nums[i];
                gcd[i] = get_gcd(nums[i], ps[i]);
                continue;
            }
            ps[i] = max(ps[i-1], nums[i]);
            gcd[i] = get_gcd(ps[i], nums[i]);
        }

        sort(gcd.begin(), gcd.end());

        int l =0;
        int r = gcd.size()-1;
        long long sum = 0;
        while(l < r){
            sum += get_gcd(gcd[l], gcd[r]);
            l++;
            r--;
        }

        return sum;
    }
};