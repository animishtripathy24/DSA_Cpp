/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(auto &it : nums)
        {
            s.insert(it);
        }
        ListNode* curr = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        while(curr != NULL)
        {
            if(s.find(curr->val) != s.end())
            {
                ListNode* nodeToDelete = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete nodeToDelete;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
