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
    ListNode* mergetwo(ListNode* list1,ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        if(temp1->val <= temp2->val) {
            temp1->next = mergetwo(temp1->next,temp2);
            return list1;
        } else {
            temp2->next = mergetwo(temp1,temp2->next);
            return list2;
        }
    }
    ListNode* partition(int st,int ed,vector<ListNode*>& lists) {
        if(st >= ed) {
            return lists[st];
        }
        if(st == ed) {
            return lists[st];
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