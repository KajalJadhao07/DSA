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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        vector<int> vec;
        ListNode* temp = head;

        while(temp != nullptr){
            vec.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(vec.begin(), vec.end());
        int i =0;

        temp = head;
        while(temp != nullptr){
            temp -> val = vec[i];
            i++;
            temp = temp -> next;
        }

        return head;
    }
};