/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        int size1 = 0;
        ListNode* temp1 = headA;
        while(temp1) {
            size1++;
            temp1 = temp1->next;
        }
        ListNode* temp2 = headB;
        int size2 = 0;
        while(temp2) {
            size2++;
            temp2 = temp2->next;
        }
        int diff = abs(size2 - size1);
        temp1 = headA;
        temp2 = headB;
        int i = 0;
        while(i < diff) {
            if(size1 > size2) {
                temp1 = temp1->next;
            } else {
                temp2 = temp2->next;
            }
            i++;
        }

        while(temp1) {
            if(temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};