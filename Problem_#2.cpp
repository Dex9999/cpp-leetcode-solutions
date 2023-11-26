//2. Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current = l1;
        ListNode* current2 = l2;
        ListNode* resultHead = nullptr;
        ListNode* resCurrent = nullptr;
        
        string revAdded = "";
        int val1 = 0;
        int val2 = 0;
        int add = 0;
        // max 18 so you only carry once
        bool carry = false;
        
        while(current != nullptr || current2 != nullptr){
            val1 = 0;
            val2 = 0;
            
            if(current == nullptr){
                val1 = 0;
            } else{
                val1 = current->val;
                current = current->next;
            }
            if(current2 == nullptr){
                val2 = 0;
            } else{
                val2 = current2->val;
                current2 = current2->next;
            }
            
            
            add = val1 + val2;
            if(carry){++add;}
            
            carry = false;
            
            if(add >= 10){
                add %= 10;
                carry = true;
            }
            revAdded = revAdded + to_string(add);
        }
        // clean up final carry
        if(carry){
                revAdded = revAdded + to_string(1);
            }
        
        
        //turn string into linked list
        for(int i = 0; i<revAdded.length(); ++i){
            //ascii representation of int to actual int    v
            ListNode* newThing = new ListNode(revAdded[i]-'0');
            
            if(resultHead == nullptr){
                resultHead = newThing;
                resCurrent = newThing;
            } else{
                resCurrent->next = newThing;
                resCurrent = newThing;
            }
        }
        
        return resultHead;
    }
};

/*
Stats

Runtime: 15ms
Beats 90.83% of users with C++
Memory: 71.72 MB
Beats 51.67% of users with C++
*/
