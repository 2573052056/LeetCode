/*************************************************************************
	> File Name: leetcode-24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时08分35秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
        struct ListNode ret, *p, *q;
        ret.next = head;
        p = &ret;
        q = head;
        while (q && q->next) {
                p->next = q->next;
                q->next = p->next->next;
                p->next->next = q;
                p = q;
                q = q->next; 
        }
        return ret.next;
}
