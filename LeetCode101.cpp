/*************************************************************************
	> File Name: LeetCode101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 14时57分49秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//根节点的两个子树比作两棵树，分别比较
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {//传入两颗树的根节点
    if (p == NULL && q == NULL) return true;//如果两棵子树都是空的，返回是
    if (p == NULL || q == NULL) return false;//有一个是空的，另一个不为空，不相等
    if (p->val - q->val) return false;//两节点不相等
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);//外面的和外面的相等，里面的和里面的相等，则对称
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;//如果根节点为空，说明当前是空树，算作对称
    return isSameTree(root->left, root->right);//不为空树的情况下，左子树和右子树相同则为对称树
}
