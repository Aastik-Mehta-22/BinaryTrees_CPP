#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    TreeNode *left;
    int val;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> temp;

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){

                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
        }

        return ans;

        
    }
};