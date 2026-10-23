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
    class Info {
        public:
        TreeNode* node;
        int hd;
        Info(TreeNode* node,int hd) {
            this->node = node;
            this->hd = hd;
        }
    };
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int mx = 0;
        queue<Info> q;
        q.push(Info(root,0));
        map<int,TreeNode*> mp;
        while(!q.empty()) {
            Info curr = q.front();
            q.pop();
            mp[curr.hd] = curr.node;
            if(curr.node->right != nullptr) {
                q.push(Info(curr.node->right,curr.hd+1));
            }
            mx = max(mx,curr.hd+1);
            if(curr.node->left != nullptr) {
                q.push(Info(curr.node->left,curr.hd+1));
            }
            mx = max(mx,curr.hd+1);
        }
        return mp[mx-1]->val;
    }
};