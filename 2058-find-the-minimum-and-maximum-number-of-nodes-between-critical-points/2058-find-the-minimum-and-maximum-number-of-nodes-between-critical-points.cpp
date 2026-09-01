class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;

            if ((curr->val > prev->val && curr->val > next_node->val) || 
                (curr->val < prev->val && curr->val < next_node->val)) {
                
                if (first_cp == -1) {
                    first_cp = index;
                } else {
                    min_dist = min(min_dist, index - prev_cp);
                }
                prev_cp = index;
            }

            prev = curr;
            curr = next_node;
            index++;
        }

        if (min_dist == INT_MAX) {
            return {-1, -1};
        }

        return {min_dist, prev_cp - first_cp};
    }
};