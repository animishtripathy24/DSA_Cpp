class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        Node* dummy = new Node(-1);
        dummy->next = head;
        Node* fast = dummy;
        Node* slow = dummy;
        
        //move fast by n steps
        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        Node* curr = slow->next;
        int sum = 0;
        while(curr != NULL)
        {
            sum+=curr->data;
            curr = curr->next;
        }
        return sum;
    }
};
