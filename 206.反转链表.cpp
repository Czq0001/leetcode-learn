#include <cstddef>
#include<iostream>
using namespace std;
int main(){
    return 0;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    ListNode *reverseList2(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *newHead = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        while(head){
            ListNode *tmp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = tmp;
        }
        return dummy -> next;
    }
};