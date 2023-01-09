/* 144. Binary Tree Preorder Traversal  */


class Solution {
public:
vector<int>v;
     void preoder(TreeNode*node){
         if(node==NULL) return;
      v.push_back(node->val);
      preoder(node->left);
      preoder(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preoder(root);
        return v;
    }
};