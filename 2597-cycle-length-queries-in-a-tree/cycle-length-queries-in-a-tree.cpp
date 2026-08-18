class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size() ; i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int count = 0;
            while(a!=b){
                if(a>b){
                    a = a/2;
                    count++;
                    continue;
                }
                else{
                    b = b/2;
                    count++;
                    continue;
                }
            }
            ans.push_back(count+1);
        }
        return ans;
    }
};