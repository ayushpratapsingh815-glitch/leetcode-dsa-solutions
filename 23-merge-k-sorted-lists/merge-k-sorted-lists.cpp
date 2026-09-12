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
    ListNode* mergetwo(ListNode* lists1,ListNode* lists2) {
        if(lists1 == nullptr && lists2 == nullptr) {
            return nullptr;
        }
        if(lists1 == nullptr) {
            return lists2;
        }
        if(lists2 == nullptr) {
            return lists1;
        }

        ListNode* temp1 = lists1;
        ListNode* temp2 = lists2;
        if(temp1->val <= temp2->val) {
            temp1->next = mergetwo(temp1->next,temp2);
            return temp1;
        } else {
            temp2->next = mergetwo(temp1,temp2->next);
            return temp2;
        }
    }
    ListNode* partition(int st,int ed,vector<ListNode*>& lists) {
        if(st == ed) {
            return lists[st];
        }
        if(st >= ed) {
            return nullptr;
        }
        int mid = st + (ed - st) / 2;
        ListNode* part1 = partition(st,mid,lists);
        ListNode* part2 = partition(mid+1,ed,lists);
        return mergetwo(part1,part2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) {
            return nullptr;
        }
        return partition(0,k-1,lists);
    }
};