class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x==1)
        {
            Node* temp=head->next;
            head->next=NULL;
            temp->prev=NULL;
            head=temp;
            return head;
        }
        //we have to move to that position
        Node* temp=head;
        for(int i=1;i<x-1;i++)
        {
            temp=temp->next;
        }
        Node* nodeToDelete=temp->next;
        temp->next=nodeToDelete->next;
        nodeToDelete->prev=NULL;
        delete nodeToDelete;
        return head;
    }
};
