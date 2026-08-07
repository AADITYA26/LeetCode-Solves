class Solution {
public:
    int decodings(string &s ,int i  , vector<int> &dp){
        if(i<-1)return 0;
        if(i==0||i==-1)return 1;
        if(dp[i]!=-1)return dp[i];
        int take = 0;
        int nottake =0;
        if(s[i]!='0')nottake = decodings(s , i-1,dp);
        if(stoi(s.substr(i-1,2))<=26&&s[i-1]!='0')take = decodings(s , i-2,dp);
        return dp[i] = take + nottake;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() , -1);
        if(s[0]=='0')return 0;
        int n = s.size();
        return decodings(s , n-1 , dp);
    }
};