struct node {
	int data;
	struct node * next;
};

//precondition:  headP points to a linked list pointer
//postcondition:  the list has a new element added to the top
void addToTop(struct node ** headP, int data);

//precondition:  head is a linked list
//postcondition:  the contents of the list has been printed
void printList(struct node * head);

//precondition:  headP points to a non-empty linked list pointer
//postcondition:  the top element in the list has been removed 
//return: the data value of the removed element
int removeFromTop(struct node ** headP);

//precondtion:  head is a linked list
//postcondition:  pa and pb point to linked lists which each contain half
//				  of the elements of head's linked list
void splitList(struct node * head, struct node ** pa, struct node ** pb);

//precondition: a and b both point to sorted linked lists
//return:  the head of a sorted linked list that contains all the
//		   elements from a and b 
struct node * sortedMerge(struct node * a, struct node * b);

//precondition:  phead points to a linked list
//postcondition:  phead is now sorted
void mergeSort(struct node ** phead);