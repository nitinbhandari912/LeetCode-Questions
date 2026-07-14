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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=nullptr){
            if(temp->next->val==temp->val){
                ListNode* temp1=temp->next;
                while (temp1 != nullptr && temp1->val == temp->val) {
                    temp1 = temp1->next;
                }
                temp->next=temp1;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};