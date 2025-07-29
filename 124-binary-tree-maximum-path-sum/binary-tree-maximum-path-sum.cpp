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
    int dfs(TreeNode* root,int& maxsum){

        if(root==0) return NULL;

        int left=max(0,dfs(root->left,maxsum));
        int right=max(0,dfs(root->right,maxsum));

        int currpath=root->val+left+right;
        maxsum=max(currpath,maxsum);

        return root->val+max(left,right);


    }    
public:
    int maxPathSum(TreeNode* root) {

        int maxsum=INT_MIN;
        dfs(root,maxsum);  
        return maxsum;  
    }
};