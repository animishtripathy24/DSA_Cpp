class KthLargest {
private:
    //declaring a min heap
    priority_queue<int,vector<int>,greater<int>>pq;
    int kNew;
public:
    KthLargest(int k, vector<int>& nums) {
        this->kNew=k;
        for(auto &it:nums)
        {
            pq.push(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>kNew)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
