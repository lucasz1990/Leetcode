#include <iostream>
using namespace std;


//singly-linked list 
//
class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        uint64_t L1_value = 0;
        uint64_t L2_value = 0;
        uint64_t SUM = 0;
        int i;
        
        
        for (i = 1; l1 !=NULL; i*=10, l1 = l1->next) {
            L1_value = L1_value + l1->val * i;
        }
        for (i = 1; l2 !=NULL; i*=10, l2 = l2->next) {
            L2_value = L2_value + l2->val * i;
        }

        SUM = L1_value + L2_value;
        ListNode *node = new ListNode(SUM%10);
        ListNode *head;
        ListNode *tail;
        head = node;
        tail = node;

        for (i = 10; SUM/i > 0 ; i*=10) {
            int integer;
            integer = (SUM % (i * 10)) / i; 

            ListNode *node = new ListNode(integer);
            
            tail->next = node;
            tail = tail->next;
        }


        return head;

    }
};

/**/

int main() {
    ListNode Input1_1(9);
    //ListNode Input1_2(4);
    //ListNode Input1_3(3);
    
    ListNode Input2_1(1);
    ListNode Input2_2(9);
    ListNode Input2_3(9);

    //Input1_1.next = &Input1_2;
    //Input1_2.next = &Input1_3;
    
    Input2_1.next = &Input2_2;
    Input2_2.next = &Input2_3;

    ListNode *IT = &Input1_1;

    //cout<< IT->val << " " << IT->next->val << " " << IT->next->next->val << " \n"; 

    Solution sb;
    ListNode *Result;

    Result = sb.addTwoNumbers(&Input1_1, &Input2_1);
    cout << Result->val << "\n";
    cout << Result->next->val << "\n";
    cout << Result->next->next->val << "\n";
    cout << Result->next->next->next->val << "\n";

    return 0;

}
