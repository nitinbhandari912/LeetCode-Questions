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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while(curr != nullptr) {
                values.push_back(curr->val);
                curr = curr->next;
            }
        }
        if (values.empty()) {
            return nullptr;
        }
        sort(values.begin(),values.end());
        ListNode* head=new ListNode(values[0]);
        ListNode* temp=head;
        for(int i=1;i<values.size();i++){
            ListNode* temp1=new ListNode(values[i]);
            temp->next=temp1;
            temp=temp->next;
        }
        return head;
    }
};