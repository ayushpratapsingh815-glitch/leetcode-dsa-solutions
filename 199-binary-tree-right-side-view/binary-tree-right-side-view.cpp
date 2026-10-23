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
            this->node = node;;
            this->hd = hd;
        }
    };
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        queue<Info> q;
        map<int,TreeNode*> mp;
        q.push(Info(root,0));
        while(!q.empty()) {
            Info curr = q.front();
            q.pop();
            mp[curr.hd] = curr.node;
            if(curr.node->left != nullptr) {
                q.push(Info(curr.node->left,curr.hd+1));
            }
            if(curr.node->right != nullptr) {
                q.push(Info(curr.node->right,curr.hd+1));
            }
        }

        for(auto it : mp) {
            ans.push_back(it.second->val);
        }
        return ans;
    }
};