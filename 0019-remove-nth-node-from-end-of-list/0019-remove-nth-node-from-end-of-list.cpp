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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        int len = 0;

        while(temp != nullptr){
            len++;
            temp = temp -> next;
        }

        if(len == n){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt = len - n + 1;

        temp = head;
        ListNode* prev = nullptr;
        int pos = 1;

        while (temp != nullptr) {

            if (pos == cnt) {
                prev->next = temp->next;
                delete temp;
                break;
            }

            prev = temp;
            temp = temp->next;
            pos++;
        }

        return head;
    }
};