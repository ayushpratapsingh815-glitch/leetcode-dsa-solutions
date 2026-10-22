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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()) {
            vector<int> temp;
            stack<int> st;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(!flag) {
                    st.push(curr->val);
                } else {
                    temp.push_back(curr->val);
                }
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            flag = !flag;
            while(!st.empty()) {
                temp.push_back(st.top());
                st.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};