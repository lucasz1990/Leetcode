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
        
        int sum = (l1->val + l2->val) % 10;
        int overflow = (l1->val + l2->val) / 10;

        ListNode result(sum);

        ListNode *Result;
        
        
        while (l1->next != NULL || l2->next != NULL || overflow == 1) {

            if(l1->next != NULL) {
                l1 = l1->next
            }
            else {
                ListNode end1(0);
                l1 = &end1;
            }

            if(l2->next != NULL) {
                l2 = l2->next
            }
            else {
                ListNode end2(0);
                l2 = &end2;
            }




            


        }
        
        ListNode *IT;
        result.next = IT;


        
        
        
        
        
        
        Result = &result;
        return Result;

    }
};

/**/

int main() {
    ListNode Input1_1(2);
    ListNode Input1_2(4);
    ListNode Input1_3(3);
    
    ListNode Input2_1(5);
    ListNode Input2_2(6);
    ListNode Input2_3(4);

    Input1_1.next = &Input1_2;
    Input1_2.next = &Input1_3;
    
    Input2_1.next = &Input2_2;
    Input2_2.next = &Input2_3;

    ListNode *IT = &Input1_1;

    cout<< IT->val << " " << IT->next->val << " " << IT->next->next->val << " \n"; 

    Solution sb;
    ListNode *Result;

    Result = sb.addTwoNumbers(&Input1_1, &Input2_1);
    cout << Result->val << "\n";

    return 0;

}
