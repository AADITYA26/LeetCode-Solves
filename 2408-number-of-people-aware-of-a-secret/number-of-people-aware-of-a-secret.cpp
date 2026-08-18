class Solution {
public:
    int helper(int n , int delay , int forget , int day , vector<int>&dp){
        if(day>n)return 0;
        if(dp[day]!=-1)return dp[day];
        long long ans = 0;
        if(day + forget > n)
        ans = 1;
        long long MOD = 1e9 + 7;
        for(int i = day+delay ; i < day+forget && i<= n ; i++){
            ans+=helper( n , delay , forget , i , dp);
            ans = ans%MOD;
        }
        return dp[day] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1 , -1);
        return helper(n , delay , forget , 1 , dp);
    }
};