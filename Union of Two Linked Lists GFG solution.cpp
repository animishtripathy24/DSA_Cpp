/*
// structure of the node is as follows

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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int>s;
        struct Node* dummy=new struct Node(-1);
        struct Node* temp=dummy;
        auto curr1=head1;
        auto curr2=head2;
        
        while(curr1!=NULL)
        {
            s.insert(curr1->data);
            curr1=curr1->next;
        }
        
        while(curr2!=NULL)
        {
            s.insert(curr2->data);
            curr2=curr2->next;
        }
        
        for(auto &value:s)
        {
            struct Node* temp1=new struct Node(value);
            temp->next=temp1;
            temp=temp->next;
        }
        
        return dummy->next;
    }
};
