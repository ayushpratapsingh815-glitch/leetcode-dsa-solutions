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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr && k == 0) {
            return true;
        }
        if(root == nullptr || k == 0) {
            return false;
        }
        vector<int> temp = inorder(root);
        int st = 0;
        int ed = temp.size() - 1;
        while(st < ed) {
            int sum = temp[st] + temp[ed];

            if(sum == k) {
                return true;
            } else if(sum < k) {
                st++;
            } else {
                ed--;
            }
        }
        return false;
    }
};