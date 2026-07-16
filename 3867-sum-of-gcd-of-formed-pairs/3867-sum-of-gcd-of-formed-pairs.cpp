class Solution {
public:
    int get_gcd(int num1, int num2){
        if(num2 == 0){
            return num1;
        }
        return get_gcd(num2, num1 % num2);
    }
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];

        for(int i=0; i<nums.size(); i++){
            mx = max(mx, nums[i]);
            nums[i] = get_gcd(mx, nums[i]);
        }

        sort(nums.begin(), nums.end());

        int l =0;
        int r = nums.size()-1;
        long long sum = 0;
        while(l < r){
            sum += get_gcd(nums[l], nums[r]);
            l++;
            r--;
        }

        return sum;
    }
};