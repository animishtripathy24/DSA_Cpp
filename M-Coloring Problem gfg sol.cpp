class Solution{
private:
    bool isSafe(int node,int color[],bool graph[101][101],int n,int col)
    {
        for(int k=0;k<n;k++)
        {
            if(k!=node && graph[k][node]==1 && color[k]==col)
            {
                return 0;
            }
        }
        return 1;
    }
    bool solve(int node,int color[],int m,int n,bool graph[101][101])
    {
        if(node == n)
        {
            return 1;
        }
        //try out for all the colors
        for(int i=1;i<=m;i++)
        {
            if(isSafe(node,color,graph,n,i))
            {
                color[node]=i;
                if(solve(node+1,color,m,n,graph))
                {
                    return 1;
                }
                color[node]=0;
            }
        }
        return 0;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        //at first we have to initialize a visited array
        int color[n]={0};
        if(solve(0,color,m,n,graph))
        {
            return 1;
        }
        return 0;
    }
};
