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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        vector<int> vec;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            if(temp!=nullptr)  sum+=temp->val;
            if(temp!=nullptr && temp->val==0){
                vec.push_back(sum);
                sum=0;
            }
        }
        ListNode* head1=new ListNode(vec[0]);
        ListNode* temp1=head1;
        for(int i=1;i<vec.size();i++){
            ListNode*node=new ListNode(vec[i]);
            temp1->next=node;
            temp1=temp1->next;
        }
        return head1;
    }
};