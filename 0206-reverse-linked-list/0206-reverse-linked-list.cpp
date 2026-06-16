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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        vector<int> list;
        while(head!=NULL){
            list.push_back(head->val);
            head=head->next;
        }
        ListNode* head1=new ListNode(list[list.size()-1]);
        ListNode* temp=head1;
        for(int i=list.size()-2;i>=0;i--){
            temp->next=new ListNode(list[i]);
            temp=temp->next;
        }
        return head1;
    }
};