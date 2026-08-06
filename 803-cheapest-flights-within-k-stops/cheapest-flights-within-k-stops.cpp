class Solution {
public:
    class Edge{
        int v;
        int wt;
        Edge(int v  ,int w){
            v = v;
            wt = w;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> q;//src price stops
        vector<int> dist(n,INT_MAX);
        q.push({src,0 , -1});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int u = x[0];
            int cost = x[1];
            int stops = x[2];
            for(auto flight : flights){
                if(flight[0]==u){
                    if(dist[flight[1]]>cost+flight[2]&&stops+1<=k){
                        dist[flight[1]] = flight[2]+cost;
                        q.push({flight[1],dist[flight[1]] , stops+1});
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};