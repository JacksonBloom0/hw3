#include "llrec.h"
//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        return;
    }

    Node* curr = head;
    head = nullptr;
    if (curr->val < pivot) {
        smaller = curr;
        llpivot(curr->next, smaller->next, larger, pivot);
    }
    else {
        larger = curr;
        llpivot(curr->next, smaller, larger->next, pivot);
    }
}
