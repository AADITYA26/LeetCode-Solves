class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long , long long> map;
        vector<long long> ans(5,0);
        for(int i = 0 ; i < coordinates.size() ; i++){
            int r = coordinates[i][0];
            int c = coordinates[i][1];
            long long x = 1LL*r*n + c;
            if(r<m-1&&c<n-1)map[1LL*r*n + c]++;
            if(r-1>=0&&c<n-1)map[1LL*(r-1)*n + c]++;
            if(c-1>=0&&r<m-1)map[1LL*r*n + c-1]++;
            if(r-1>=0&&c-1>=0)map[1LL*(r-1)*n + c-1]++;
        }
        for(auto x : map){
            ans[x.second]++;
        }
        ans[0] = 1LL*(n-1)*(m-1) - accumulate(ans.begin(),ans.end() , 0);
        return ans;

    }
};