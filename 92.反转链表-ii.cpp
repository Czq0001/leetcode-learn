#include<iostream>
using namespace std;
int main(){
    return 0;
}
/*
@lc app=leetcode.cn id=92 lang=cpp
 *
[92] 反转链表 II
 */

// @lc code=start

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int k = right - left;
        ListNode *dummy = new ListNode(0,head);
        int p = 1;
        ListNode *prevnode = dummy;
        while(p < left) {
            prevnode = prevnode->next;
            p ++;
        }
        ListNode *cur = prevnode->next; 
        while(p <= right) {
            ListNode *tmp = cur->next;
            prevnode ->next = cur;
            
            cur = tmp;
            p++;
        }
    }
};
// @lc code=end

