class Solution {
public:
    int helper(vector<int> &days , vector<int>&costs , int i , int final , vector<vector<int>>& dp){
        if(i==days.size())return 0;
        if(dp[i][final]!=-1)return dp[i][final];
        if(days[i]<=final)return dp[i][final] = 0 + helper(days , costs , i+1 , final , dp);
        else {
            int mini = 1e9;
            mini = min(mini , costs[0] + helper(days , costs , i+1 , days[i] , dp));
            mini = min(mini , costs[1] + helper(days , costs , i+1 , days[i]+6 , dp)); 
            mini = min(mini , costs[2] + helper(days , costs , i+1 , days[i]+29 , dp)); 
            return dp[i][final] = mini;
        }
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(days[n-1]+30,-1));
        return helper(days , costs , 0 , 0 , dp);
    }
};