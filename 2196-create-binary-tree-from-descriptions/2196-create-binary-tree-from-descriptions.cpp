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
 struct ChildPair{
    int left=-1;
    int right=-1;
 };
class Solution {
public:
    TreeNode* buildTreeHelper(int currval,unordered_map<int, ChildPair>& treeStructure){
        if(currval==-1) return nullptr;
        TreeNode* node=new TreeNode(currval);
        if(treeStructure.find(currval)!=treeStructure.end()){
            ChildPair children = treeStructure[currval];
            node->left=buildTreeHelper(children.left,treeStructure);
            node->right=buildTreeHelper(children.right,treeStructure);
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_set<int> parents;
        unordered_set<int> children;
        for(int i=0;i<n;i++){
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            parents.insert(parent);
            children.insert(child);
        }
        int root=0;
        for(auto it : parents){
            if(children.find(it)==children.end()){
                root=it;
            }
        }
        unordered_map<int, ChildPair> treeStructure;
        for(auto it : descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];
            if(isleft==1){
                treeStructure[parent].left = child;
            }
            else if(isleft==0){
                treeStructure[parent].right=child;
            }
        }
        return buildTreeHelper(root, treeStructure);
    }
};