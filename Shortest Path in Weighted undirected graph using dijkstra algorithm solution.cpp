class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //at first we have to convert it into graph
        vector<pair<int,int>>adj[n+1];
        for(auto &it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        //now we have to declare parent array
        vector<pair<int,int>>parent(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i].first=i;
            parent[i].second=0;
        }
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int distance=it.first;
            int node=it.second;
            
            for(auto &it:adj[node])
            {
                int adjNode=it.first;
                int adjDist=it.second;
                if(distance+adjDist<dist[adjNode])
                {
                    dist[adjNode]=distance+adjDist;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode].first=node;
                    parent[adjNode].second=dist[adjNode];
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int>path;
        int node=n;
        int sum=0;
        while(parent[node].first!=node)
        {
            path.push_back(node);
            sum+=parent[node].second;
            node=parent[node].first;
        }
        path.push_back(1);
        path.push_back(sum);
        reverse(path.begin(),path.end());
        return path;
        
    }
};
