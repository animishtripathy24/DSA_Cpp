/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        // edge case 
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        //we will initialize two pointer
        Node* last = NULL;
        Node* curr = head;
        
        while( curr != NULL )
        {
            last=curr->prev;
            curr->prev=curr->next;
            curr->next= last;
            curr=curr->prev;
            
        }
        return last->prev;
    }
};
