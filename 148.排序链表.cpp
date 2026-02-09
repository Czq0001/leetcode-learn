#include <iostream>
using namespace std;
int main() {
    return 0;
}
/*
@lc app=leetcode.cn id=148 lang=cpp
 *
[148] 排序链表
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
    ListNode *splitN(ListNode *head,int len){
        while(--len && head){
            head = head->next;
        }
        if(!head) return nullptr;
        ListNode *cur = head -> next;
        head->next = nullptr;
        return cur;
    }
    ListNode* merge(ListNode *left,ListNode *right){
        ListNode *dummy = new ListNode(0,left);
        ListNode *cur = dummy;
        while(left && right){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left?left:right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        ListNode*dummy  = new ListNode(0,head);

        int len = 0;
        for(ListNode *i = dummy->next;i!= nullptr;i = i->next) len ++;
        ListNode *left,*right,*tail;
        for(int i = 1;i < len;i *= 2){
            ListNode *tmp = dummy->next;
            tail = dummy;
            while(tmp){
                left = tmp;
                right = splitN(tmp,i);
                tmp = splitN(right,i);
                tail->next = merge(left,right);
                while(tail->next) tail = tail->next;
            }
        }
        return dummy->next;
    }
};

//len = 1   %->1->2->3->4
//
// @lc code=end

