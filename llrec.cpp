#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // check if head is NULL

  if (head==NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }
  // set up pointer to current head and the node in advance
  Node* current = head;
  Node* advance = head->next;
  // recursively call
  llpivot(advance, smaller, larger, pivot);
  // check if current val is smaller or larger than pivot and sort accordingly
  if (current->val <= pivot) {
    current->next = smaller;
    smaller = current;
  } else {
    current->next = larger;
    larger = current;
  }

  head = NULL;

}