/*************************************************************************
	> File Name: LeetCode107.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时16分45秒
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//获取当前树的最大深度
int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;//空树
    int left = getDepth(root->left), right = getDepth(root->right);//遍历左右子树
    return (left > right ? left : right) + 1;//左右子树最大值加上当前节点
}
//获取每一层的节点个数，放到cnt里
void getCnt(struct TreeNode *root, int k, int *cnt) {
    if (root == NULL) return ;//空树
    cnt[k] += 1;//从下标为1的位置开始存储
    getCnt(root->left, k - 1, cnt);//递归遍历左子树
    getCnt(root->right, k - 1, cnt);//递归遍历右子树
    return;
}

void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if (root == NULL) return ;//空树
    ret[k][cnt[k]++] = root->val;//放在第k层第k++的元素
    getResult(root->left, k - 1, cnt, ret);//左
    getResult(root->right, k - 1, cnt, ret);//右
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);//将要获得树的最大深度
    int *cnt = (int *) calloc(sizeof(int) , depth);//一维数组记录每一层的节点个数
    int **ret = (int **)malloc(sizeof(int *) * depth);//二维数组存储地址
    getCnt(root, depth - 1, cnt);//计算每一层的节点个数size值，倒着存储，层数变为n - 1
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);//每一位开辟一个空间
        cnt[i] = 0;//保证size数组可继续利用，不需要再开一个数组
    }
    getResult(root, depth - 1, cnt, ret);//节点，当前下标值
    *returnSize = depth;//传出参数，当前ret数组的行数，层数
    *returnColumnSizes = cnt;//传出参数，被地址赋值
    return ret;
}
