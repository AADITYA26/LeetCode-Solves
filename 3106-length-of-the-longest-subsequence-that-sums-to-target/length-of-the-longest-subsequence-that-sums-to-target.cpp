class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;

        for (int x : nums) {
            for (int t = target; t >= x; t--) {
                if (dp[t - x] != -1)
                    dp[t] = max(dp[t], dp[t - x] + 1);
            }
        }

        return dp[target];
    }
};