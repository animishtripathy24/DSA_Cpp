class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>newQ;
        vector<int>ans;
        
        //first half of the queue ko new queue me daal dena hai
        int size=q.size()/2;
        int count=0;
        while(!q.empty() && count < size)
        {
            newQ.push(q.front());
            q.pop();
            count++;
        }
        //jab tak new queue empty na ho jaye traverse karte raho
        while(!newQ.empty() && !q.empty())
        {
            ans.push_back(newQ.front());
            newQ.pop();
            int value=q.front();
            q.pop();
            ans.push_back(value);
        }
        return ans;
    }
};
