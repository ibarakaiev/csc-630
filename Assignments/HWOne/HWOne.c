#include <stdlib.h>
#include <stdio.h>
#include "HWone.h"

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
    struct node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.");
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int length(struct node* head) {
    struct node* temp = head;
    int length = 0;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    return length;
}

int sum(struct node* head) {
    struct node* temp = head;
    int sum = 0;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

int getNth(struct node *head, int index) {
    if (index < 0) {
        return -1;
    }
    struct node* temp = head;
    int i = 0;
    while (i < index) {
        temp = temp->next;

        if (temp == NULL) {
            return -1;
        }
        i++;
    }

    return temp->data;
}

void insertNth(struct node** headP, int data, int index) {
    if (index == 0) {
        addToTop(headP, data);
        return;
    } else if (index > 0) {
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        struct node* temp = *headP;
        int i = 0;
        while (i < index - 1) {
            temp = temp->next;

            if (temp == NULL) {
                return;
            }
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void removeAll(struct node** headP) {
    while (*headP != NULL) {
        struct node* temp = *headP;
        *headP = (*headP)->next;
        free(temp);
    }
}
