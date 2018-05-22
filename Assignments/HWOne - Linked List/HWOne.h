struct node {
	int data;
	struct node * next;
};


// precondition:  headP points to a linked list pointer
// postcondition:  the list has a new element added to the top
void addToTop(struct node ** headP, int data);

// precondition:  headP points to a non-empty linked list pointer
// postcondition:  the top element in the list has been removed 
// return: the data value of the removed element
int removeFromTop(struct node ** headP);

// precondition:  head is a linked list
// postcondition:  the contents of the list has been printed
void printList(struct node * head);

// precondition:  head is a linked list
// return: the number of nodes on the list
int length(struct node * head);

// precondtion:  head is a non-empty linked list
// return: the sum of all data values on the list
int sum(struct node * head);

// precondition: head is a linked list and 0 <= index < length(head)
// return: the data value at node n
int getNth(struct node * head, int index);

// precondition: headP points to a linked list pointer, 0 <= index <= length(head)
void insertNth(struct node ** headP, int data, int index);

// precondtion: headP points to a linked list pointer
// postcondition: all elements of the list have been removed
void removeAll(struct node ** headP);
