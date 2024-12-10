
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    
    int diameter = 0;
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        cout<<leftHeight<<" "<<rightHeight<<" "<<root->val;
        diameter =  max(diameter,leftHeight+rightHeight);
        cout<<" "<<diameter<<endl;

        return 1 + max(leftHeight,rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        
        height(root); // we can also pass the refrence of  diameter in function by decraling it in the main function

        return diameter;

    }
};