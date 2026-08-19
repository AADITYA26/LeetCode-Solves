class Solution {
public:

    int bfs(vector<vector<int>> &grid ,  int r , int c){
        queue<tuple<int , int , int>> mq;
        queue<pair<int,int>> q;
        q.push({r ,c});
        grid[r][c] = 2;
        while(!q.empty()){
            auto [r ,c]= q.front();
            mq.push({r , c , 0});
            q.pop();
            if(r+1<grid.size()&&grid[r+1][c]==1){
                grid[r+1][c] = 2;
                q.push({r+1 ,c});
            }
            if(r-1>=0&&grid[r-1][c]==1){
                grid[r-1][c] = 2;
                q.push({r-1 ,c});
            }
            if(c+1<grid.size()&&grid[r][c+1]==1){
                grid[r][c+1] = 2;
                q.push({r ,c+1});
            }
            if(c-1>=0&&grid[r][c-1]==1){
                grid[r][c-1] = 2;
                q.push({r ,c-1});
            }
        }
        int ans = INT_MAX;
        while(!mq.empty()){
            auto [r , c , x] = mq.front();
            mq.pop();
            if(r+1<grid.size()){
                if(grid[r+1][c]==1)ans = min(ans , x);
                else if(grid[r+1][c]==0){
                    grid[r+1][c] = 2;
                    mq.push({r+1 ,c , x+1});
                }
            }
            if(r-1>=0){
                if(grid[r-1][c]==1)ans = min(ans , x);
                else if(grid[r-1][c]==0){
                    grid[r-1][c] = 2;
                    mq.push({r-1 ,c , x+1});
                }
            }
            if(c+1<grid.size()){
                if(grid[r][c+1]==1)ans = min(ans , x);
                else if(grid[r][c+1]==0){
                    grid[r][c+1] = 2;
                    mq.push({r ,c+1 , x+1});
                }
            }
            if(c-1>=0){
                if(grid[r][c-1]==1)ans = min(ans , x);
                else if(grid[r][c-1]==0){
                    grid[r][c-1] = 2;
                    mq.push({r ,c-1 , x+1});
                }
            }
        }
        return ans;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid.size() ; j++){
                if(grid[i][j]==1)return bfs(grid , i , j);
            }
        }
        return -1;
    }
};