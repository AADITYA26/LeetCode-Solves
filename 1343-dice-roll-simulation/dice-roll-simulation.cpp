class Solution {
public:

    int dieSimulator(int n, vector<int>& rollMax) {
        long long MOD = 1e9+7;
        vector<vector<vector<long long>>> dp (n+1 , vector<vector<long long>>(6 , vector<long long>(16,0)));
        for(int i = 0 ; i < 6 ; i++ )dp[1][i][1] = 1;
        for(int i = 2 ; i < n+1 ; i++){
            for(int j = 0 ; j < 6 ; j++){
                for(int k = 1 ; k < 16 ; k++){
                    if(k<rollMax[j]){
                        dp[i][j][k+1] += dp[i-1][j][k]; 
                    }
                    for(int p = 0 ; p < 6 ; p++){
                        if(p!=j){
                            dp[i][p][1] = (dp[i][p][1]+ dp[i-1][j][k])%MOD;
                        }
                    }
                }
            }
        }
        long long sum = 0;
        for(int i = 0 ; i < 6 ; i++){
            for(int j =1 ; j < 16 ; j++){
                sum=(sum+dp[n][i][j])%(MOD);
            }
            sum = sum%(MOD);
        }
        return sum;
    }
};