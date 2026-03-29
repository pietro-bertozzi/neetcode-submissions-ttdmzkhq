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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* merged = dummy;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                merged->next = l1;
                l1 = l1->next;
            } else {
                merged->next = l2;
                l2 = l2->next;
            }
            merged = merged->next;
        }
        merged->next  = l1 ? l1 : l2;
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2;
        }
        return lists[0];
    }
};
