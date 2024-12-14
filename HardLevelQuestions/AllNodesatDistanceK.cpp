#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                
                q.push(node->left);
                parent[node->left] = node;
            } 
            if(node->right){
                
                q.push(node->right);
                parent[node->right] = node;
            }
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(root == NULL) return {};

        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int level = 0;

        while(!q.empty()){

            int sz = q.size();

            if(level == k) break;

            level++;

            for(int i = 0;i<sz;i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parent[node] && !visited[parent[node]]){

                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }

        vector<int> result;
        while(!q.empty()){

            TreeNode* ele = q.front();
            q.pop();

            result.push_back(ele->val);
        }


        return result;
    


    }  
};