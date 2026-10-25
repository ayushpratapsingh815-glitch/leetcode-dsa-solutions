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
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        vector<int> left = inorder(root->left);
        for(int num : left) {
            ans.push_back(num);
        }

        ans.push_back(root->val);

        vector<int> right = inorder(root->right);
        for(int num : right) {
            ans.push_back(num);
        }

        return ans;
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        vector<int> temp = inorder(root);

        for(int i=0; i<temp.size()-1; i++) {
            if(temp[i] >= temp[i+1]) {
                return false;
            }
        }
        return true;
    }
};