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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        vector<int> value;
        while(head!=nullptr){
            value.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<value.size();i+=k){
            if(i+k>value.size()) break;
            reverse(value.begin()+i,value.begin()+i+k); 
        }
        ListNode* head1=new ListNode(value[0]);
        ListNode* temp1=head1;
        for(int i=1;i<value.size();i++){
            ListNode* temp=new ListNode(value[i]);
            temp1->next=temp;
            temp1=temp1->next;
        }
        return head1;
    }
};