class Solution {
public:
    bool hasCycle(ListNode *head) {

        //if the list is empty or contains only one element
        if(head==NULL || head->next==NULL)
        {
            return 0;
        }

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast !=NULL)
        {
            fast=fast->next;
            if(fast != NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow)
            {
                return 1;
            }

        }
        return 0;
        
    }
};
