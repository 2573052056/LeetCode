/*************************************************************************
	> File Name: LeetCode100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 14时57分35秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//采用递归方式

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;//判断两个树是否为空，两棵空树相等
    if (p == NULL || q == NULL) return false;//一棵树为空，另一棵树不为空两树肯定不相等
    if (p->val - q->val) return false;//两棵树当前节点值不相等，肯定不相等
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//左子树右子树都相等，都成立，两棵树相同
}
