
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
    TreeNode* solve(vector<int> &inorder,vector<int> &postorder,int &index,int start,int end,unordered_map<int,int> &mpp){
        if(index < 0 || start > end){
            return NULL;
        }

        int ele = postorder[index--];


        TreeNode* node = new TreeNode(ele);
        
        int pos = mpp[ele];

        node->right = solve(inorder,postorder,index,pos+1,end,mpp);
        node->left = solve(inorder,postorder,index,start,pos-1,mpp);

        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();

        unordered_map<int,int> mpp;

        for(int i = 0;i<n;i++){

            mpp[inorder[i]] = i;
            
        }
        int index =  n-1;
       return  solve(inorder,postorder,index,0,n-1,mpp);
    }
};