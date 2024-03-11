// User function Template for C++
class Solution {
  private:
    void dfs(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&s)
    {
        //at first we have to mark the node as visited
        vis[node]=1;
        for(auto &it:adj[node])
        {
            int v=it.first;
            if(!vis[v])
            {
                dfs(v,adj,vis,s);
            }
        }
        
        s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //at first we have to make a graph
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        //now we have to perform topo sort
        int vis[N]={0};
        stack<int>s;
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,s);
            }
        }
        
        //now we have to make distance array
        vector<int>dis(N);
        for(int i=0;i<N;i++)
        {
            dis[i]=1e9;
        }
        //we have to mark the distance of the source node as 0
        dis[0]=0;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            
            for(auto &it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dis[node]+wt<dis[v])
                {
                    dis[v]=dis[node]+wt;
                }
            }
        }
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]==1e9)
            {
                dis[i]=-1;
            }
        }
        return dis;
    }
};
