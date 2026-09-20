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

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        /*slow is the head of the second half of our linked list*/
        ListNode* prev=nullptr;
        ListNode* curr=second;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        /*prev is the head of the reversed list, now we alternatively merge these two*/
        ListNode dummy(0);
        ListNode* tail=&dummy;
        ListNode* curr1=head;
        while(curr1!=nullptr && prev!=nullptr){
            tail->next=curr1;
            curr1=curr1->next;
            tail=tail->next;
            tail->next=prev;
            prev=prev->next;
            tail=tail->next;
        }
        if(curr1!=nullptr){
            tail->next=curr1;
        }
        else{
            tail->next=prev;
        }
    }
};
