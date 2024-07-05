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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        ListNode* curr=head;
        vector<int>ans;
        int index=1;
        while(curr != NULL)
        {
            if(curr != head && curr->next != NULL && ((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)))
            {
                ans.push_back(index);
            }
            prev=curr;
            curr=curr->next;
            index++;
        }
        if(ans.size()<=1)
        {
            return {-1,-1};
        }
        sort(ans.begin(),ans.end());
        int maxi=ans.back()-ans[0];
        int mini=INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            mini=min(mini,(ans[i+1]-ans[i]));
        }
        return {mini,maxi};
    }
};
