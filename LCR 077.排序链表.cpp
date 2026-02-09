#include<iostream>
using namespace std;
/*
@lc app=leetcode.cn id=LCR 077 lang=cpp
@lcpr version=30307
 *
[LCR 077] 排序链表
 */

// @lc code=start
/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *split(ListNode* head,int step){
        if(!head) return nullptr;
        for(int i = 1;i < step&&head->next;i++){
            head = head->next;
        }
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }
    pair<ListNode*, ListNode*> mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a ? a : b);

        while (tail->next) tail = tail->next; // 走到合并链表的尾部
        return {dummy.next, tail};
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;

        int n = 0;
        for(ListNode *p = head;p;p=p->next) n ++;
        ListNode dummy(0);
        dummy.next = head;
        for(int step = 1;step<n;step<<=1){
            ListNode *cur = dummy.next;
            ListNode *pre = &dummy;
            while(cur){
                ListNode *left = cur;
                ListNode *right = split(left, step);
                cur = split(right, step);

                auto [mergedhead,mergedTail] = mergeTwo(left, right);
                pre->next = mergedhead;
                pre = mergedTail;
            }
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

