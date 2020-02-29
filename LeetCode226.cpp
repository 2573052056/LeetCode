/*************************************************************************
	> File Name: LeetCode226.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时39分41秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;//空树
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;//根节点的左右子树互换
    invertTree(root->left), invertTree(root->right);//递归调用自身，分别遍历左右子树，完成全部翻转
    return root;//返回树
}
