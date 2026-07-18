class Solution {
public:
    int get_gcd(int nums1, int nums2){
        if(nums2 == 0){
            return nums1;
        }
        return get_gcd(nums2, nums1 % nums2);
    }
    int findGCD(vector<int>& nums) {
        int min_ele = *min_element(nums.begin(), nums.end());
        int max_ele = *max_element(nums.begin(), nums.end());

        return get_gcd(max_ele, min_ele);
    }
};