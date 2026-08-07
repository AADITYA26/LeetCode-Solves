class Solution {
public:
    double dfs(string src , string dst ,  unordered_map<string , list<pair<string,double>>> adjList , unordered_set<string> &visited ){
        if(src==dst)return 1;
        visited.insert(src);
        for(auto & x : adjList[src]){
             string v = x.first;
            double value  = x.second;
            if(!visited.contains(v)){
                double res = dfs(v , dst , adjList , visited);
                if(res!=-1)return value * res;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , list<pair<string,double>>> adjList ;
        for(int i  = 0 ; i < equations.size() ; i++){
            adjList[equations[i][0]].push_back({equations[i][1] , 1.0*values[i]});
            adjList[equations[i][1]].push_back({equations[i][0] , 1.0/values[i]});
        }
        vector<double> ans(queries.size(),-1);
        for(int i = 0 ; i < queries.size() ; i++){
            unordered_set<string> visited;
            string src = queries[i][0];
            string dst = queries[i][1];
            if(adjList.find(src)==adjList.end()||adjList.find(dst)==adjList.end()){
                continue;
            }
            double ans_ = dfs(src , dst , adjList ,visited );
            ans[i] = ans_;
        }
        return ans;
    }
};