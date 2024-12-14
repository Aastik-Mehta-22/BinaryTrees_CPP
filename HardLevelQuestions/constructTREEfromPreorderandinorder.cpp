
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
    TreeNode* solve(vector<int> &preorder,vector<int> &inorder,int start,int end,int &index,int n,unordered_map<int,int> &mpp){

        if( index >= n || start > end) return NULL;

        int ele = preorder[index++];

        TreeNode* node = new TreeNode(ele);

        int pos = mpp[ele];

        node->left = solve(preorder,inorder,start,pos-1,index,n,mpp);
        node->right = solve(preorder,inorder,pos+1,end,index,n,mpp);

        return node;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();

        unordered_map<int,int> mpp;

        for(int i = 0;i<n;i++) mpp[inorder[i]] = i;
        int index = 0;

        return solve(preorder,inorder,0,n-1,index,n,mpp);
    }

};