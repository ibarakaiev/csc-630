//Name:  Igor Barakaiev

#include "HWTwo.h"
#include <stdlib.h>
#include <stdio.h>

void addToTop(struct node** headP, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headP;
    *headP = newNode;
}

int removeFromTop(struct node** headP) {
    int removedData = (*headP)->data;
    struct node* secondNode = (*headP)->next;
    free(*headP);
    *headP = secondNode;

    return removedData;
}

void printList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.");
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void splitList(struct node* head, struct node** pa, struct node** pb) {
    // calculate length to determine where is the half
    // NOTE: using two pointers, it is possible to avoid 
    // going through list 1.5 times 
    // (not implemented here but should be for a perfect grade)
    int length = 0;
    struct node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    // set pa to point to the first node
    *pa = head;
    if (length == 1)
        return;
    temp = head;
    for (int i = 1; i < length / 2; i++, temp = temp->next);

    // split the list in the middle and set pb to point to the second half
    *pb = temp->next;
    temp->next = NULL;
}

struct node* sortedMerge(struct node* a, struct node* b) {
    if (b == NULL) return a;

    // set the first node
    struct node* head;
    if (a->data < b->data) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
    struct node* origin = head;

    // choose the smaller node and append
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            head->next = a;
            a = a->next;
        } else {
            head->next = b;
            b = b->next;
        }
        head = head->next;
    }

    // add the remaining nodes if one of the halves is empty
    while (a != NULL) {
        head->next = a;
        a = a->next;
        head = head->next;
    }
    while (b != NULL) {
        head->next = b;
        b = b->next;
        head = head->next;
    }

	return origin;
}

void mergeSort(struct node** phead) {
    if (*phead == NULL || (*phead)->next == NULL) return;

    struct node* pa = NULL;
    struct node* pb = NULL;

    splitList(*phead, &pa, &pb);

    mergeSort(&pa);
    mergeSort(&pb);

    *phead = sortedMerge(pa, pb);
}
