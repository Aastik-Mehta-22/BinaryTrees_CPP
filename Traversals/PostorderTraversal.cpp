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
    void findPostorder(TreeNode* root,vector<int> &ans){

        if(root == NULL){
            return ;
        }

        findPostorder(root->left,ans);
        findPostorder(root->right,ans);
        ans.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        

        vector<int> ans;

        findPostorder(root,ans);

        return ans;

    }
};

int main() {
    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Creating a Solution object to call the function
    Solution sol;

    // Performing Postorder traversal
    vector<int> result = sol.postorderTraversal(root);

    // Printing the result
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleaning up allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;



    return 0;
}
