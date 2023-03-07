#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {


    ListNode* list1 = new ListNode(0);
    int size = 8;
    int arr[] = { 1,7,4,2,8,3,9,5 };

    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(4);






}

//ListNode* createList(int arr[], int size) {
//    int size = 0;
//    for () {
//        size++;
//
//    }
//
//
//}




ListNode* insertionSortList(ListNode* head) {

    ListNode* unsortedListHead = head->next;

    ListNode* sortedListHead = head;

    sortedListHead->next = nullptr; //detaching the list

    while (unsortedListHead != NULL) {
        ListNode* current = unsortedListHead;
        unsortedListHead = unsortedListHead->next;//move up the unsortedListHead
        //check if the current value is less than the sortedListHeads value
        if (current->val < sortedListHead->val) {
            //if current if less that the first value of the sortedList
            current->next = sortedListHead;//change currents pointed to the head of the sorted list
            sortedListHead = current;//update the head of the sorted list to be that of current
        }
        else {
            //check the sorted list to see where current belongs
            ListNode* search = sortedListHead;
            //while the next element is still there and the next element is great than current's value
            while (search->next != NULL && current->val > search->next->val) {
                search = search->next;
            }
            //changes currents pointer to either null (if last in sorted list), or node in sorted list with greater value
            current->next = search->next;
            //changes node before current to point to current
            search->next = current;
        }



    }

    return sortedListHead;
}
