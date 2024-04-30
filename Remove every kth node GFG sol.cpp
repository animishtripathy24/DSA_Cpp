/* Link list Node 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
    private:
    int getLength(Node* head)
    {
        int count=0;
        Node* curr=head;
        while(curr != NULL)
        {
            count++;
            curr=curr->next;
        }
        return count;
    }
    void solve(Node* head,Node* &curr,int len,int &ans,int k)
    {
        //base case
        if(ans>len)
        {
            return;
        }
        
        //we have to remove the kth node
        Node* prev=NULL;
        for(int i=1;i<k;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        
        //remove the element
        Node* nodeToDelete = curr;
        Node* temp=curr->next;
        if (prev) 
        {
            prev->next = curr->next;
        } 
        else 
        {
            head = curr->next;
        }
        delete nodeToDelete;
    
        //recursive call
        ans=ans+k;
        solve(head,temp,len,ans,k);
        
    }
    public:
    Node* deleteK(Node *head,int K){
        if(K==1)
        {
            return NULL;
        }
        //at first we have to find the length of the linked list
        int len=getLength(head);
        
        if(K>len)
        {
            return head;
        }
        
        //then we will declare an ans variable whivh is at first initialized to k;
        int ans=K;
        
        Node* curr=head;
        //we will now make a recursive call;
        solve(head,curr,len,ans,K);
        
        return head;
    }
};
