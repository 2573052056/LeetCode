/*************************************************************************
	> File Name: LeetCode235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 19时24分33秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* __lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val == p->val) return p;//p是父节点
    if (root->val == q->val) return q;//q是父节点
    if (p->val < root->val && q->val > root->val) return root;//p，q是根节点的两个左右子节点，返回它们的父节点
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);//当前的值不在这棵子树的左子树里，递归调用本身遍历右子树
    return __lowestCommonAncestor(root->left, p, q);
}//递归调用本身，遍历左子树

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;//空树
    if (p->val == q->val) return p;//p，q值相等返回p或q
    if (p->val > q->val) {//p编号比q大
        struct TreeNode *temp = p;
        p = q;
        q = temp;//交换p，q
    }
    return __lowestCommonAncestor(root, p, q);
}
