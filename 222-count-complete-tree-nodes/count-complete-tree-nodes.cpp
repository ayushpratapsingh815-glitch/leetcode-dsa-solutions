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
    int leftheight(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->left;
        }
        return h;
    }
    int rightheight(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->right;
        }
        return h;
    }

    bool check(TreeNode* root) {
        int l = leftheight(root->left);
        int r = rightheight(root->right);
        if(l != r) {
            return false;
        } else {
            return true;
        }
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int h = leftheight(root);
        if(check(root)) {
            return pow(2,h) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};