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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode* res;
        if(list1->val <= list2->val){
            res = list1;
            list1 = list1->next;
        }
        else{
            res = list2;
            list2 = list2->next;
        }
        ListNode* temp = res;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                res->next = list1;
                res = res->next;
                list1 = list1->next;
            }
            else{
                res->next = list2;
                res = res->next;
                list2 = list2->next;
            }
        }
        while(list1 != NULL){
            res->next = list1;
            list1 = list1->next;
            res = res->next;
        }
        while(list2 != NULL){
            res->next = list2;
            list2 = list2->next;
            res = res->next;
        }
        res->next = NULL;
        return temp;
    }
};