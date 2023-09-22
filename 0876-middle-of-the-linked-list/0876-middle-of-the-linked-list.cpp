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
    ListNode* middleNode(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* singleJ = head;
        ListNode* doubleJ = head;
        while(doubleJ != NULL && doubleJ->next != NULL){
            singleJ = singleJ->next;
            doubleJ = doubleJ->next->next;
        }
        return singleJ;
    }
};