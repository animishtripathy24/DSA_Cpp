void solve(queue<int>&q)
{
    if(q.empty())
    {
        return;
    }
    
    char front=q.front();
    q.pop();
    
    solve(q);
    
    q.push(front);
}
queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}
