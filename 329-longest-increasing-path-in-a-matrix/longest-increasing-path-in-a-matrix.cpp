class Solution {
public:
    int maxPath(vector<vector<int>>& matrix , int r  ,int c , vector<vector<int>> &dp){
        if(r<0||r>=matrix.size()||c<0||c>=matrix[0].size())return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        int up = 0 ;int down = 0 ;int left = 0;int right = 0;
        if(r-1>=0 && matrix[r-1][c] > matrix[r][c])up = 1+maxPath(matrix,r-1,c,dp);
        if(r+1<matrix.size() && matrix[r+1][c] > matrix[r][c])down = 1+maxPath(matrix,r+1,c,dp);
        if(c+1<matrix[0].size() && matrix[r][c+1] > matrix[r][c])right = 1+maxPath(matrix,r,c+1,dp);
        if(c-1>=0 && matrix[r][c-1] > matrix[r][c])left = 1+maxPath(matrix,r,c-1,dp);
        return dp[r][c] = max({left,right,up,down});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = -1e9;
        int r = matrix.size();
        vector<vector<int>> dp(r,vector<int>(matrix[0].size() , -1));
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                maxi = max(maxPath(matrix,i,j,dp),maxi);
            }
        }
        return 1 +maxi;
    }
};