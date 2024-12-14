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
    TreeNode* target;
    void  markParents(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*> &parent){

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) target = node;

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

    int amountOfTime(TreeNode* root, int start) {

        if(root == NULL) return 0;

        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(root,start,parent);

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        bool flag = false;

        int time = 0;


        while(!q.empty()){

            int sz = q.size();

            flag = false;

            for(int i = 0;i<sz;i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                    flag = true;
                }
                
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                    flag = true;
                }

                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                    flag = true;                 
                }



            }

            if(flag == true) time++;

        }

        return time;




    
    }
};