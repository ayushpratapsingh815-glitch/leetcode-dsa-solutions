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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }
        if(head->next == nullptr) {
            return head;
        }
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            size++;
        }
        k = k % size;
        if(k == 0) {
            return head;
        }
        temp = head;
        ListNode* prev = nullptr;
        while(temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
        temp = head;
        int i = 0;
        temp = head;
        while(i < k) {
            temp = temp->next;
            i++;
        }
        prev = nullptr;
        while(temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        ListNode* prevNode = prev;
        temp = head;
        int count = 0;
        while(count < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }
        head = prevNode;
        return head;
    }
};