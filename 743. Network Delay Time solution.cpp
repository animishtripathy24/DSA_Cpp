class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto &it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k}); //{distance,node}
        vector<int>dist(n+1);
        for(int i=1;i<=n;i++)
        {
            dist[i]=1e9;
        }
        dist[k]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int distance=it.first;
            int node=it.second;

            for(auto &it:adj[node])
            {
                int edgeWt=it.second;
                int v=it.first;
                if(distance+edgeWt<dist[v])
                {
                    dist[v]=distance+edgeWt;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dist[i]);
        }
        if(ans == 1e9)
        {
            return -1;
        }
        return ans;
    }
};
