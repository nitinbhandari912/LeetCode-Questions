/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set1;
        while(headA!=nullptr){
            set1.insert(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            if(set1.find(headB)!=set1.end()){
                return headB;
            }
            headB=headB->next;
        }
        return nullptr;
    }
};