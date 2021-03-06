/*************************************************************************
	> File Name: LeetCode257.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 20时25分22秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <math.h>
//获取路径数量
int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;//空
    if (root->left == NULL && root->right == NULL) return 1;//左右子树都为空，只有一个根节点
    return getPathCnt(root->left) + getPathCnt(root->right);//递归求出左右子树的和
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt = getResult(root->left, len, k, ret, buff);
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);//路径
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);//二维数组
    int max_len = 10000;//最大长度
    char *buff = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buff);
    free(buff);
    *returnSize = pathCnt;
    return ret;
}
