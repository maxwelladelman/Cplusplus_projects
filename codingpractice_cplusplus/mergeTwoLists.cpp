#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main() {



    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(0);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);

    ListNode* combinedList = mergeTwoLists(list1, list2);

    ListNode* temp = combinedList;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
   
    ListNode* combined = new ListNode(0);
    ListNode* temp = combined; // temp points to head of combined
    ListNode* l1 = list1;// l1 points to head of combined
    ListNode* l2 = list2;// l2 points to head of combined

    while (l1 != nullptr && l2 != nullptr) {

        if (l1->val < l2->val) {
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        else if (l2->val < l1->val) {
            temp->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        else {

            //l1 and l2 are equal in values
            temp->next = new ListNode(l1->val);
            temp = temp->next;
            temp->next = new ListNode(l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    // add the remaining items of the lists
    if (l1 != NULL) {
        temp->next = l1; // point to the remaining items of the l1 list
    }

    if (l2 != NULL) {
        temp->next = l2; // point to the remaining items of the l2 list
    }

    // return the combined list, skipping the dummy head
    return combined->next;
 


}
