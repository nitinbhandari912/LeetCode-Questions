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
    vector<double> averageOfLevels(TreeNode* root) {
       vector<double> avg;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        int level=q.size();
        long long curr_sum=0;
        for(int i=0;i<level;i++){
            TreeNode* curr=q.front();
            q.pop();
            curr_sum+=curr->val;
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=nullptr) q.push(curr->right);
        }
        avg.push_back((double)curr_sum/(double)level);
       }
       return avg; 
    }
};