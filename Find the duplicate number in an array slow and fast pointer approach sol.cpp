int Solution::repeatedNumber(const vector<int> &nums) {
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        //move slow by one step
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    
    //now assign fast to nums[0]
    //and move fast and slow pinter by one one step
    fast = nums[0];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
