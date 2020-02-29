/*************************************************************************
	> File Name: LeetCode104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时15分06秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;//树为空，返回0
    int d1 = maxDepth(root->left);//左子树开始遍历最大深度
    int d2 = maxDepth(root->right);//右子树开始遍历最大深度
    return fmax(d1, d2) + 1;//左右子树最大深度加上当前节点，+1
}
