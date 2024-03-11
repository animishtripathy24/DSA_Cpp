// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //at first we have to create a graph
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=1;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        //then we have to declare a distance vector
        vector<int>dist(N);
        for(int i=0;i<N;i++)
        {
            dist[i]=1e9;
        }
        dist[src]=0;
        //now we have to declare a queue data structure
        queue<pair<int,int>>q; //{node , distance}
        //at first we have to push the src node with distance 0;
        q.push({src,0});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int node=it.first;
            int distance=it.second;
            
            for(auto &it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[v])
                {
                    dist[v]=dist[node]+wt;
                    q.push({v,dist[v]});
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};
