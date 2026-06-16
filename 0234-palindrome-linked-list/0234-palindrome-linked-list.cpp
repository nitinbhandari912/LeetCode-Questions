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
    bool isPalindrome(ListNode* head) {
        vector<int> palindrom;
        while(head!=nullptr){
            palindrom.push_back(head->val);
            head=head->next;
        }
        int left=0;
        int right=palindrom.size()-1;
        while(left<=right){
            if(palindrom[left]!=palindrom[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};