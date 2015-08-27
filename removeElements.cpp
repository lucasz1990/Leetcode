#include <iostream>

using namespace std;

//Definition for singly-linked list.
class ListNode {
public:
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(0);
        
        if (head==NULL) return head;      

        //if head is the value
        while (head->val == val){
            if (head->next == NULL)    return NULL;
            head = head ->next;
        }

        p->next = head;
        do{
            if (p->next == NULL)    return head;

            while (p->next->val == val){
                p->next = p->next->next;
                if (p->next == null) return head;
            }
            p = p->next;
        }
        while (p != NULL);
        //*/
        return head;
    }
};

int main() {
    ListNode* input = new ListNode(1);
    ListNode* input2 = new ListNode(2);
    ListNode* output = new ListNode(0);

    input -> next = input2;

    Solution sb;
    output = sb.removeElements(input, 2);

    cout<<output->val<<"\n";


}
