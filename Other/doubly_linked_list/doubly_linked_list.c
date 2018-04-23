#include <stdio.h>
#include <stdlib.h>

// note: this implementation was not thoroughly checked but it is highly likely that it is correct

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void addToTop(struct node** headP, struct node** tailP, int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *headP;
    temp->prev = NULL;
    if (*tailP == NULL) {
        *tailP = temp;
    }
    (*headP)->prev = temp;
    *headP = temp;
}

int removeFromTop(struct node** headP, struct node** tailP) {
    struct node* temp = *headP;
    int data = temp->data;
    if (*headP == *tailP) {
        free(*headP);
        *headP = NULL;
        *tailP = NULL;
    } else {
        temp = (*headP)->next;
        free(*headP);
        *headP = temp;
        (*headP)->prev = NULL;
    }

    return data;
}

void addToBottom(struct node** headP, struct node** tailP, int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = *tailP;
    if (*headP == NULL) {
        *headP = temp;
    } else {
        (*tailP)->next = temp;
    }
    *tailP = temp;
}

int removeFromBottom(struct node** headP, struct node** tailP) {
    struct node* temp = *tailP;
    int data = temp->data;
    if (*headP == *tailP) {
        free(*headP);
        *headP = NULL;
        *tailP = NULL;
    } else {
        temp = (*tailP)->prev;
        free(*tailP);
        *tailP = temp;
        (*tailP)->next = NULL;
    }

    return data;
}

void removeAllOccurences(int data, struct node** headP, struct node** tailP) {
    struct node* temp = *headP;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp == *headP) {
                temp = temp->next;
                removeFromTop(headP, tailP);
            } else if (temp == *tailP) {
                temp = temp->next;
                removeFromBottom(headP, tailP);
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                struct node* t = temp->prev;
                free(temp);
                temp = t;
            }
        } else {
            temp = temp->next;
        }
    }
}

struct node* append(struct node** headF, struct node** tailF, struct node** headS, struct node** tailS) {
    if (*headF == NULL) return *headS;
    if (*headS == NULL) return *headF;
    (*tailF)->next = *headS;
}

void removeAll(struct node** headP, struct node** tailP) {
    while (*headP != NULL) {
        removeFromTop(headP, tailP);
    }
}

void printForwards(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void printBackwards(struct node* tail) {
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }

    printf("\n");
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;

    addToBottom(&head, &tail, 6);
    addToBottom(&head, &tail, 7);
    addToBottom(&head, &tail, 7);
    addToBottom(&head, &tail, 7);
    addToBottom(&head, &tail, 7);
    addToBottom(&head, &tail, 7);
    addToBottom(&head, &tail, 6);

    printForwards(head);
    printBackwards(tail);
    removeAllOccurences(7, &head, &tail);
    removeAllOccurences(6, &head, &tail);
    printForwards(head);
    printBackwards(tail);

    return 0;
}
