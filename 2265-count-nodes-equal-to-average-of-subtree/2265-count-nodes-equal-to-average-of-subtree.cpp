/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int matchCount = 0;
    pair<int, int> dfs(TreeNode* node){
        if (node == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        int currentSum = left.first + right.first + node->val;
        int currentCount = left.second + right.second + 1;
        if (currentSum / currentCount == node->val) {
            matchCount++;
        }
        return {currentSum, currentCount};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchCount;
    }
};