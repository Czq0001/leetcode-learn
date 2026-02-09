#include<iostream>
#include<vector>
int main(){
    return 0;
}
/*
@lc app=leetcode.cn id=25 lang=cpp
 *
[25] K 个一组翻转链表
 */

// @lc code=start
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0,head);
        int length = 0;
        ListNode *temp1 = head;
        while(temp1){
            length ++;
            temp1 = temp1->next;
        }
        if(length < k) {
            return head;
        }
        ListNode *preGroupEnd = dummy;
        while(length >= k){
            ListNode *Groupstart =  preGroupEnd -> next;
            ListNode *Groupend = Groupstart;
            for(int i = 1; i < k ;i ++) Groupend = Groupend->next;
            ListNode *nextGroupstart = Groupend->next;
            ListNode *cur = Groupstart;
            ListNode *pre = nextGroupstart;
            while(cur != nextGroupstart) {
                ListNode *temp2= cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp2;
            }

            preGroupEnd -> next = Groupend;
            preGroupEnd = Groupstart;
            length -= k;
        }
        return dummy -> next;
    }
};
// @lc code=end

