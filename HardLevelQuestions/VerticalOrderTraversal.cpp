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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        map<int,vector<pair<int,int>>> mpp; // column , row ,value;

        
        queue<pair<TreeNode*,int>> q; // node , col

        q.push({root,0});
        int row = 0;
        while(!q.empty()){

            int sz = q.size();

            for(int i = 0;i<sz;i++){
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                int col = it.second;

                mpp[col].push_back({row,node->val});

                if(node->left) q.push({node->left,col-1});
                if(node->right) q.push({node->right,col+1});
            }


            row++;
        }




        for(auto& it : mpp){

            sort(it.second.begin(),it.second.end());

            vector<int> temp;

            for(auto ele : it.second){

                temp.push_back(ele.second);
            }

            ans.push_back(temp);
        }

        return ans;



    }
};



// DFS Approach

class Solution {
public:
    void solve(TreeNode* root,map<int,vector<pair<int,int>>>& mpp,int row,int col){

        if(root == NULL){
            return ;
        }

        mpp[col].push_back({row,root->val});

        solve(root->left,mpp,row+1,col-1);
        solve(root->right,mpp,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        map<int,vector<pair<int,int>>> mpp; // column , row ,value;

        solve(root,mpp,0,0); // root,mpp,row,column


        for(auto& it : mpp){

            sort(it.second.begin(),it.second.end());

            vector<int> temp;

            for(auto ele : it.second){

                temp.push_back(ele.second);
            }

            ans.push_back(temp);
        }

        return ans;



    }
};