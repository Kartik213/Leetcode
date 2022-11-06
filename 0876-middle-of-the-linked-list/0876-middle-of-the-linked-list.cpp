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
        
//         ListNode *slow = head, *fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
        
        ListNode *temp = head;
        int n=0;
        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }
        temp = head;
        if(n%2 == 0){
            for(int i=0;i<n/2;i++){
                temp = temp->next;
            }
        }
        else{
            for(int i=0;i<n/2 + 1;i++){
                temp = temp->next;
            }
        }
        return temp;
    }
};