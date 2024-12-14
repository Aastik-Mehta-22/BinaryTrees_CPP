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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* currNode = q.front();
            q.pop();

            if(currNode == NULL) s.append("#,");
            else s.append(to_string(currNode->val) + ',');

            if(currNode != NULL){

                q.push(currNode->left);
                q.push(currNode->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        stringstream s(data);

        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');

            if(str == "#"){
                node->left = NULL;
            }
            else{

                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }


            getline(s,str,',');

            if(str == "#"){
                node->right = NULL;
            }
            else{

                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }



        }


        return root;;
        

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));