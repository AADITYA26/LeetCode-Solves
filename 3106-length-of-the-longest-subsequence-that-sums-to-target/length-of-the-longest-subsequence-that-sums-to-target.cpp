class Solution {
public:
    int helper(vector<int>& nums, int target, int i,
               vector<vector<int>>& dp) {
        
        if (target == 0)
            return 0;

        if (i == nums.size() || target < 0)
            return -1;

        if (dp[i][target] != -2)
            return dp[i][target];

        int take = helper(nums, target - nums[i], i + 1, dp);
        if (take != -1)
            take++;

        int skip = helper(nums, target, i + 1, dp);

        return dp[i][target] = max(take, skip);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -2));

        return helper(nums, target, 0, dp);
    }
};