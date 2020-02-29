/*************************************************************************
	> File Name: LeetCode102.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 15时22分52秒
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
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//获取当前树的深度
int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;//树为空，返回0
    int l = getDepth(root->left), r = getDepth(root->right);//l为当前节点的左子树遍历返回的最大深度，r为当前节点的右子树遍历返回的最大深度
    return (l > r ? l : r) + 1;//返回最深的那个再加上当前这个节点的深度，所以再+1
}
//确定当前层数节点个数的值
void getCnt(struct TreeNode *root, int k, int *cnt) {//传入树，第几层开始找，找完存哪
    if (root == NULL) return ;//如果树为空返回
    cnt[k] += 1;//层数+1，下标和层数相等，从下标第一号开始存
    getCnt(root->left, k + 1, cnt);//左子树遍历
    getCnt(root->right, k + 1, cnt);//右子树遍历
    return ;
}
//向二维数组中放值
void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {//树，第k层，cnt数组，存到二维数组ret
    if (root == NULL) return ;//树为空返回
    ret[k][cnt[k]++] = root->val;//把当前节点放在第k层的第几个里
    getResult(root->left, k + 1, cnt, ret);//递归遍历左子树
    getResult(root->right, k + 1, cnt, ret);//递归遍历右子树
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** columnSizes) {//理解为二维数组
    int depth = getDepth(root);//存储通过当前树的根节点获取的树的深度
    int *cnt = (int *)calloc(sizeof(int), depth);//定义一个指针，相当于ret后的每一个数组的首地址，每个ret里一个int*，如果地址不存在，相当于存一个NULL，一维数组返回首地址最好先把下面清空，所以用calloc，cnt用于初始化ret的第二个维度
    int **ret = (int **)malloc(sizeof(int *) * depth);//返回层序遍历的二维数组，先开辟depth这么大的空间
    getCnt(root, 0, cnt);//传入根节点，从哪一层算，存到cnt数组里，cnt[0] = 1, cnt[1] = 2, cnt[2] = 2
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);//每一个维度开cnt[i]空间
        cnt[i] = 0;//每使用完cnt[i]，知道每一层的节点数，用完cnt[i],等于0，保证cnt数组继续使用，不用再开辟一个新的数组
    }
    getResult(root, 0, cnt, ret);//根节点，第0层开始，cnt数组，向二维数组中放值
    *returnSize = depth;//指向整形的指针变量指向第一维的维度depth
    *columnSizes = cnt;//数组首地址cnt
    return ret;//返回二维数组
}
