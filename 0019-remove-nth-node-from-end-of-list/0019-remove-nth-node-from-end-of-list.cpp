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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        int totalLength = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            totalLength++;
            curr = curr->next;
        }
        if (totalLength == n) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        ListNode* temp = head;
        for (int i = 0; i < totalLength - n - 1; i++) {
            temp = temp->next;
        }
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        return head;
    }
};