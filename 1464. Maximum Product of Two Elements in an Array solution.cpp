class Solution {
public:
    int maxProduct(vector<int>& nums) {

        //creating a max heap
        priority_queue<int>maxi;
        if(nums.size()<2)
        {
            return -1;
        }
        else if(nums.size()==2)
        {
            return ((nums[0]-1)*(nums[1]-1));
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                maxi.push(nums[i]);
            }
            int a=-1;
            int b=-1;

            while(!maxi.empty())
            {
                a=maxi.top();
                maxi.pop();
                b=maxi.top();
                maxi.pop();
                break;

            }
            return ((a-1)*(b-1));
        }
        
    }
};
