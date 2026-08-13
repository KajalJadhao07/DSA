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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != nullptr && temp2 != nullptr){
            int value = temp1 -> val + temp2 -> val + carry;
            temp1 -> val = value % 10;
            carry = value /10;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next; 
        }

        if(temp2 != nullptr){
            temp1  = temp2;

            ListNode* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }

            last->next = temp1;

            while(temp2 != nullptr){
                int value = temp2 -> val + carry;
                temp2 -> val = value % 10;
                carry = value /10;
                temp2 = temp2 -> next;
            }
        }else{
            while (temp1 != nullptr && carry != 0) {
                int value = temp1->val + carry;
                temp1->val = value % 10;
                carry = value / 10;
                temp1 = temp1->next;
            }
        }

        
        if (carry != 0) {

            ListNode* last = head;

            while (last->next != nullptr) {
                last = last->next;
            }

            last->next = new ListNode(carry);
        }

        return head;
    }
};