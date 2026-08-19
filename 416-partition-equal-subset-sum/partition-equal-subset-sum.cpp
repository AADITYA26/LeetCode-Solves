class Solution {
public:
    bool helper(vector<int> & nums , int i  ,int target , vector<vector<int>> &dp){
        if(i==nums.size() && target!=0)return false;
        if(i==nums.size() && target ==0)return true;
        if(target<0)return false;
        if(dp[i][target]!=-1)return dp[i][target];
        bool pick = helper(nums , i+1 , target-nums[i] , dp);
        bool notpick = helper(nums , i+1 , target ,dp);
        return dp[i][target] = pick||notpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum%2!=0)return false;
        vector<vector<int>> dp(nums.size() , vector<int>(sum/2+1 , -1));
        return helper(nums , 0 , sum/2 , dp);
    }
};