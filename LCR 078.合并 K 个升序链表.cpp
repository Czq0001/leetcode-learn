#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 078 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 078] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode *mergeTwo(ListNode *a,ListNode *b){
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while(a && b){
            if(a->val < b->val){
                cur->next = a;
                a = a->next;
            }else{
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if(a){
            cur->next = a;
        }
        if(b) cur->next = b;
        return dummy->next; 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        ListNode *dummy = new ListNode();
        dummy->next = lists[0];
        for(int i = 1;i < lists.size();i++){
            dummy->next = mergeTwo(dummy->next, lists[i]);
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

