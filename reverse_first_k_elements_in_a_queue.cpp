// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>s;
    //first k element ko fetch karke stack me daal dena hai..
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    //stack se element fetch karke wapas queue me daal dena hai...
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    //baaki bacche n-k element ko last me daal dena hai..
    for(int i=0;i<q.size()-k;i++)
    {
        int element=q.front();
        q.pop();
        q.push(element);
    }
    
    return q;
}
