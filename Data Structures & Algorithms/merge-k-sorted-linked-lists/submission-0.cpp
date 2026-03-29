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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* old = dummy;
        int best, ibest = -1;
        bool todo = true;
        while (todo) {
            best = 1000, todo = false;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val <= best) {
                    todo = true;
                    best = lists[i]->val;
                    ibest = i;
                }
            }
            if (todo) {
                old = old->next = lists[ibest];
                lists[ibest] = lists[ibest]->next;
            }
        }
        return dummy->next;
    }
};
