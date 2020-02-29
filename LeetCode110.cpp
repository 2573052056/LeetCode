/*************************************************************************
	> File Name: LeetCode110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时55分44秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/*int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;//空树
    int d1 = maxDepth(root->left);//递归遍历左子树最大值
    int d2 = maxDepth(root->right);//递归遍历右子树最大值
    if (d1 == -2 || d2 == -2 || abs(d1 - d2) > 1) return -2;
    return fmax(d1, d2) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return maxDepth(root) >= 0;
}*/

int Depth(struct TreeNode *root) {
    if (root == NULL) return 0;//空树
    int l = Depth(root->left), r = Depth(root->right);//左右子树
    return (l > r ? l : r) + 1;//最大值加一
}

bool isBalanced(struct TreeNode *root) {
    if (root == NULL) return true;//空树
    int l = Depth(root->left), r = Depth(root->right);//遍历左右子树
    if (abs(l - r) > 1) return false;//绝对值大于1
    return isBalanced(root->left) && isBalanced(root->right);//左右子树都满足
}
