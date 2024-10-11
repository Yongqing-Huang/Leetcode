struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = l1;
        ListNode* prev = l1;
        bool carry = false;
        int sum;

        // Add two numbers when both l1 and l2 have value
        while (l1 && l2){
            sum = l1->val + l2->val + carry;
            carry = sum > 9;
            l1->val = sum % 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2){ // If l1 is empty, append l2 to the back of l1.
            prev->next = l2;
        }
         
        while (carry && prev && prev->next){ // Check if there is carry left;
            prev->next->val++;
            carry = prev->next->val > 9;
            prev->next->val %= 10;
            prev = prev->next;
        }
        
        if (carry){ // Check if there is carry after all addition.
            prev->next = new ListNode(1);
        }
        return result;
    }
};