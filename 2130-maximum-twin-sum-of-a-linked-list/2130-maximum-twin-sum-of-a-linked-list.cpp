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
    int pairSum(ListNode* head) {
        vector<int> twin;
        while(head!=nullptr){
            int num=head->val;
            twin.push_back(num);
            head=head->next;
        }
        int i=0;
        int max_twin_sum=INT_MIN;
        int j=twin.size()-1;
        while(i<j){
            if(max_twin_sum<twin[i]+twin[j]){
                max_twin_sum=twin[i]+twin[j];
            }
            i++;
            j--;
        }
        return max_twin_sum;
    }
};