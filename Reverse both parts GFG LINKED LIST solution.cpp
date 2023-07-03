//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node* reverseLL(Node* head)
    {
        Node* curr=head;
        Node* next=NULL;
        Node* prev=NULL;
        
        while(curr != NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    Node* kReverse(Node* head,int k,int count)
    {
        if(count==2)
        {
            Node* new_head=reverseLL(head);
            return new_head;
        }
        //we have to reverse the first k nodes
        int c=0;
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr != NULL && c<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        if(next != NULL)
        {
            head->next=kReverse(next,k,++count);
        }
        
        return prev;
    }
   
    Node *reverse(Node *head, int k)
    {
        int count=1;
        return kReverse(head,k,count);
    }
};
