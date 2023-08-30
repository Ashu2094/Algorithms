class Solution {
public:
    int time;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n,vector<int>());
        vector<vector<int>>bridge;
        vector<bool>vis(n,false);
        vector<int>disc(n,-1),low(n,-1),parent(n,-1);
        time=0;
        for(auto x:connections){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tarjenDfs(0,adj,vis,disc,low,parent,bridge);
        return bridge;
    }


    void tarjenDfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&disc,vector<int>&low,vector<int>&parent,vector<vector<int>>&bridge){
        time++;
        vis[u] = true;
        low[u]=time;
        disc[u] = time;
        for(auto v:adj[u]){
            if(vis[v]==false){
                parent[v]=u;
                tarjenDfs(v,adj,vis,disc,low,parent,bridge);
                low[u] = min(low[v],low[u]);
                if(disc[u]<low[v])
                bridge.push_back({u,v});
            }else if(v!=parent[u]){
                low[u] = min(low[u],disc[v]);
            }
        }
    }
};
