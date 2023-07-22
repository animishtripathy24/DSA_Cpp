class Node
{
    public:
        int data;
        int row;
        int col;
    //constructor
    Node(int data,int row,int col)
    {
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class compare
{
    public:
        bool operator()(Node* a,Node* b)
        {
            return (a->data > b->data );
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int k=nums.size();
        //step-1: we have to create a min heap
        priority_queue<Node*,vector<Node*>,compare>pq;

        //step-2: insert the first element of all the arrays
        for(int i=0;i<k;i++)
        {
            int element=nums[i][0];
            //saath saath max min bhi nikal lenge
            maxi=max(maxi,element);
            mini=min(mini,element);

            //element ko minheap me push kar dena hai
            pq.push(new Node(element,i,0));

        }

        //ek start aur end pointer hoga
        int start=mini;
        int end=maxi;

        //jab tak queue empty na ho jaye tab tak processing karte raho
        while(!pq.empty())
        {
            //sabse pehle minimum ko update kar lena hai...
            Node* temp=pq.top();
            pq.pop();
            mini=temp->data;

            //update the range
            if(maxi-mini < end-start)
            {
                start=mini;
                end=maxi;
            }

            //update the maximum

            //sabse pehle check kar lena hai..ki aage wala element exist karta hai..ki ni
            if(temp->col+1 < nums[temp->row].size())
            {
                maxi=max(maxi,nums[temp->row][temp->col+1]);
                pq.push(new Node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else
            {
                //next element does not exist
                break;
            }
        }

        return {start,end};


        
    }
};
