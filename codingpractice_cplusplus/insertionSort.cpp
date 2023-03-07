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
void createList(ListNode* list, int arr[], int size);
void displayList(ListNode* list);
ListNode* insertionSortList(ListNode* head);


int main() {


    ListNode* list1 = new ListNode(0);
    int size = 8;
    int arr[] = { 1,7,4,2,8,3,9,5 };

    createList(list1, arr, size);
    cout << "unsorted\n";
    displayList(list1);
    cout << "\nsorted using insertion sort\n";

    insertionSortList(list1);
    displayList(list1);





}

void createList(ListNode* list,int arr[], int size) {
    ListNode* temp = list;//points to first element of list
    for (int k = 0; k < size; k++) {
        temp->next = new ListNode(arr[k]);
        temp = temp->next;
        

    }


}


void displayList(ListNode* list) {
    ListNode* temp = list;

    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

}

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
