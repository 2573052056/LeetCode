/*************************************************************************
	> File Name: leetcode-160.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时10分55秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*#define swap(a, b) {\
     __typeof(a) __temp = a;\
     a = b; b = __temp;\
 }
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int cntA = 0, cntB = 0;
    struct ListNode *p = headA, *q = headB;
    while (p) cntA++, p = p->next;
    while (q) cntB++, q = q->next;
    int m = cntA - cntB;
    p = headA, q = headB;
    if (m < 0) {
        swap(p, q); 
        m = -m;
        }
    while (m--) p = p->next;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
    }
}*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p != q) {
        p = p ? p->next : headB;
        q = q ? q->next : headA;
    }
    return p;
}
