
//   insertion and deletion  on Linked List at various places
#include <iostream>

using namespace std;
 
// A linked list node
class Node
{
    public:
    int data;
    Node *next;
};
 
// inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node;
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/*insert node at center */
void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node = new Node();

    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}
 // insertions at the end */
void append(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    Node *last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}
void deleteBeg(Node** head_ref){
    //if list is empty.
    Node * head=*head_ref;
    if(head==NULL)
        cout<<"LIST IS EMPTY\n";
    else
    {
        Node *temp=head;
        head = head->next;
        delete temp;
        *head_ref = head;

    }
}
 
// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
 
/* Driver code*/
int  main()
{
	Node *head = nullptr;
	int choice,data;
	
	while(1){
		

		cout<< "\t\t\n      enter 1 for insertion at begning...\n";
		cout<< "\t\t      enter 2 for insertion at center...\n";
		cout<< "\t\t      enter 3 for insertion at end....\n";
		cout<< "\t\t      enter 4 show list....\n";
		cout<< "\t\t      enter 5  for deletion at begning...\n";
		cout<< "\t\t      enter 0 to exit....\n";
		cin>>choice;
	

	  switch (choice) {
	    case 0:
		 	exit(0);
			break;
		case 1: 
			cout<<"enter data   ";
			cin>>data;
			push(&head, data);	
			break;
		case 2: 
			cout<<"enter data  ";
			cin>>data;
			insertAfter(head->next, data);
			break;
		case 3: 
			cout<<"enter data  ";
			cin>>data;
			append(&head, data);
			break;
			
		case 4:
			cout<<"Created Linked list is: ";
			printList(head);
			break;
		
		 case 5:
    		deleteBeg(&head);
    		cout<<"item deleted: ";
			break;
		
		
		default:
			printf("wrong Input\n");
		}
    
	}
	return 0;
}