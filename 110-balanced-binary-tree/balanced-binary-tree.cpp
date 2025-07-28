/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<bool,int>checking(TreeNode* root){

        if(!root){
            return {true,0};
        }

        pair<bool,int>left=checking(root->left);
        pair<bool,int>right=checking(root->right);

        bool islbal=left.first;
        bool isrbal=right.first;

        bool diff=abs(left.second-right.second)<=1;

        pair<bool,int>ans;

        ans.second=max(left.second,right.second)+1;

        if(islbal && isrbal && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }

        return ans;


    }
public:
    bool isBalanced(TreeNode* root) {

        return checking(root).first;
        
    }
};