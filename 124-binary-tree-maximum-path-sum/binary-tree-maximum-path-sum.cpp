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
    int maxsum;
    int solve(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int l = solve(root->left);
        int r = solve(root->right);
        int dono_ache_h = l + r + root->val;
        int root_achi_h = root->val;
        int ak_acha_h = max(l,r) + root->val;
        maxsum = max(maxsum,max(dono_ache_h,max(root_achi_h,ak_acha_h)));
        return max(ak_acha_h,root_achi_h);
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};