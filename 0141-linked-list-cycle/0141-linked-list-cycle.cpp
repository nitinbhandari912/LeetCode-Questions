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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> vis;
        while(head!=nullptr){
            if(vis.find(head)!=vis.end()) {
                return true;
                break;
            }
            vis.insert(head);
            head=head->next;
        }
        return false;
    }
};