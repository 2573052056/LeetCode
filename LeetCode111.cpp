/*************************************************************************
	> File Name: LeetCode111.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时17分12秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//最小深度
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;//空树，返回0
    if (root->left == NULL && root->right == NULL) return 1;//左右子树为空，只有根节点，返回1
    if (root->left == NULL || root->right == NULL)     return minDepth(root->right ? root->right : root->left) + 1;//左右子树有一个为空，返回空的那个，就是最小的那个，递归调用函数
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;//左右子树都不为空，返回小的那个，递归调用函数
}
