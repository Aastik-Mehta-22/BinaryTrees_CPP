#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            int mini = q.front().second;
            int first,last;
            for(int i = 0;i<sz;i++){
                auto temp = q.front();
                q.pop();
                long long int currId = temp.second-mini;
                TreeNode* node = temp.first;
                if(i==0) first = currId;
                if(i == sz-1) last = currId;
                if(node->left){
                    q.push({node->left,2*currId+1});
                }
                if(node->right){
                    q.push({node->right,2*currId+2});
                }
            }

            ans = max(ans,last-first+1);
        }

        return ans;
    }
};