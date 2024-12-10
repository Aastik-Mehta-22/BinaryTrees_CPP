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
    int maxiSum = INT_MIN;
    int getMaxSum(TreeNode* root){
        if(root == NULL) return 0;

        int getLeftSum = max(0,getMaxSum(root->left));
        int getRightSum = max(0,getMaxSum(root->right));


        int currSum = getLeftSum + getRightSum  + root->val;
       

    
        maxiSum = max(maxiSum,currSum);
       

        

        return root->val + max(getLeftSum,getRightSum);

    }
    int maxPathSum(TreeNode* root) {
        
        int temp = getMaxSum(root);

        return maxiSum;
        
    }
};