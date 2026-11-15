class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {

        // BASE CASE
        if(i >= nums.size()) {
            return 0;
        }

        // Already calculated
        if(dp[i] != -1) {
            return dp[i];
        }

        // INCLUDE
        int include = nums[i] + solve(nums, i + 2, dp);

        // EXCLUDE
        int exclude = solve(nums, i + 1, dp);

        return dp[i] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, dp);
    }
};