class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* temp = head;
        vector<int> nums;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = nums.size();
        k = k % n;
        if (k == 0) return head;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        
        ListNode* head1 = new ListNode(nums[0]);
        ListNode* temp1 = head1;
        for (int i = 1; i < n; i++) {
            ListNode* node = new ListNode(nums[i]);
            temp1->next = node;
            temp1 = temp1->next;
        }
        
        return head1;
    }
};