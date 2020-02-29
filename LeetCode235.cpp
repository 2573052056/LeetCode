/*************************************************************************
	> File Name: LeetCode235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 20时02分25秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /*struct TreeNode* __lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
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
        q = temp;//交换p，q,保证p比q小
    }
    return __lowestCommonAncestor(root, p, q);
}*/
/*
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode *q) {
    if (root == NULL) return NULL;//空树
    if (((root->val - p->val) * (root->val - q->val)) <= 0) return root;//一正一负，p，q为root的两个节点
    if (root->val > p->val) {
        return lowestCommonAncestor(root->left, p, q);//在左边，递归遍历左子树
    } else {
        return lowestCommonAncestor(root->right, p, q);//在右边，递归遍历右子树
    }  
}*/


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode *q) {
    if (p->val <  root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);//在左边
    else if (p->val >  root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);//在右边
    return root;//两边都不是，就是root的两个子树
}
