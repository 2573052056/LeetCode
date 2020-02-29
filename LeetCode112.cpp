/*************************************************************************
	> File Name: LeetCode112.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时36分15秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//二叉树中找一条路径，从根节点开始，一直到叶子节点相加和是否等于sum

bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return false;//空树肯定不等于sum
    if (root->left == 0 && root->right == NULL) return root->val == sum;//根节点的左右子树都为空，如果sum等于当前根节点的值， 则返回true，否则返回false
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);//递归调用自身，分别沿着左右子树找sum减去当前的值，有一条找到就返回true，没找到返回false
}
