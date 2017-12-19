
/*-----------------------------------------------------------------------------
 *  Juliusz Cezary Korczakowski
 *  Group III
 *  246817
 *	Single linked-list with basic operations like: insert, search, delete,
 *	print, drop, remove duplicates, merge 2 lists.
 *	To correct: ?
 *	Points: ?
 *	 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node_t {
	char *surname;
	struct node_t *next;
	struct node_t *prev;
} Node;

// SZUKAJ(L, s)
bool search_list(Node *head, char* search_surname)
{
	Node* current = head;
	while (current != NULL)
	{
		if(strcmp(current->surname,search_surname)==0)
			return true;
	current = current->next;
	}
	return false;
}
//WSTAW(L, s)
void push_front (Node **head, char* new_surname)
{
	Node *node = malloc(sizeof(Node));
	
	node->surname = new_surname;
	node->next = (*head);
	(*head) = node;	
}

//DRUKUJ(L)
void print_list (Node *N) {
	Node *tmp_node = N;
	if(N == NULL)
	{
		printf("List is empty!\n");
	}
	while (tmp_node)
	{
		printf("%s\n", tmp_node->surname);
		tmp_node = tmp_node->next;
	}
}

//USUŃ(s, L)
void delete_from_list (Node **head, char *del_surname) {

	//store head node
	Node* tmp = *head, *prv;
	
	// if head node itselfs hold the key to be deelted
	
	if(tmp != NULL && (strcmp(tmp->surname,del_surname)==0))
	{
		*head = tmp->next;
		free(tmp);
		return ;
	}

	// search for the key to be deleted, keep track of the
	// previous node as we need to change prev->next
	
	while(tmp != NULL && (strcmp(tmp->surname,del_surname)!=0))
	{
		prv = tmp;
		tmp = tmp->next;
	}

	// if key was not presetn in linked list
	
	if(tmp == NULL) return ;

	// unlink the node from linked list
	prv->next = tmp->next;

	free(tmp);
}


//KASUJ (L)

void dropList(Node **head)
{
	Node* current = *head;
	Node* next;
	
	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

//BEZPOWTÓRZEŃ (L)

void removeDuplicates(Node *head)
{
	Node *ptr1, *ptr2, *dup;
	char sur[sizeof(Node)];
	ptr1 = head;

	while( ptr1 != NULL && ptr1->next != NULL )
	{
		ptr2 = ptr1;

		while(ptr2->next != NULL)
		{
			if(strcmp(ptr1->surname,ptr2->next->surname)==0)
			{
				dup = ptr2->next;
				memcpy(sur,&dup,sizeof(Node));
				ptr2->next = ptr2->next->next;
				delete_from_list(&head,sur);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}


//CLONE (L)

Node *clone(Node *L1)
{
	Node* L2 = NULL;
	Node* prev = NULL;

	while(L1 != NULL)
	{
		Node *node = (Node*)malloc(sizeof(Node));

		if(node == NULL){
			printf("Failed alloc!"), exit(1);
		}

		node->surname = L1->surname;
		node->next = NULL;

		if (L2 == NULL)
		{
			L2 = node;
			prev = node;
		}
		else
		{
			prev->next = node;
			prev = node;
		}
		L1 = L1->next;
	}
return L2;
}


//SCAL(L1, L2)

Node* list_merge(Node **head1, Node **head2)
{
	Node *merged, *tmp, *ptr;

	if(head1 == NULL)
	{
		return *head2;
	}
	else if (head2 == NULL)
	{
		return *head1;
	}
	else if(head1 == NULL && head2 == NULL)
	{
		printf("Both lists are empty!");
		exit(1);
	}

	merged = clone(*head1);
	tmp = clone(*head2);
	ptr = merged;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = tmp;
	dropList(head1);
	dropList(head2);

	return merged;
	
}

int main (void)
{
	Node *head = NULL;
	Node *cloned = NULL;
	Node *merged = NULL;
	Node *node_1, *node_2;
	
	// initialising head
	head   = malloc(sizeof(Node));
	node_1 = malloc(sizeof(Node));
	node_2 = malloc(sizeof(Node));

	// initialising entries
	head->surname = strdup("Kowalski");
	head->next = node_1;
	head->prev = NULL;
	
	node_1->surname = strdup("Korczakowski");
	node_1->next = node_2;
	node_1->prev = head;
	
	node_2->surname = strdup("Grams");
	node_2->next = NULL;
	node_2->prev = node_1;

	printf("Initialized list:\n");
	print_list(head);
	printf("\n");
		
	push_front(&head, "Ababas");
	push_front(&head, "Grams");
	push_front(&head, "Ababas");
	push_front(&head, "Now");
	push_front(&head, "Jezierski");
	push_front(&head, "Nowaczyk");
	push_front(&head, "Kazmierczak");
	push_front(&head, "Frankowska");

	printf("List after adding surnames:\n");
	print_list(head);
	printf("\n");
	
	printf("Searching for surname 'Aabas'\n");
	search_list(head, "Aabas")? printf("Surname found\n") : printf("Surname not found\n");
	printf("\n");

	printf("Searching for surname 'Korczakowski'\n");
	search_list(head, "Korczakowski")? printf("Surname found\n") : printf("Surname not found\n");
	printf("\n");

	delete_from_list(&head, "Kowalski");
	delete_from_list(&head, "Korczakowski");


	printf("List after deleting 'Kowalski' and 'Korczakowski' :\n");
	print_list(head);
	printf("\n");

	cloned = clone(head);
//
//	printf("Cloned list:\n");
//	print_list(cloned);

	removeDuplicates(cloned);
	
	printf("First list with duplicates:\n");
	print_list(head);
	printf("\n");
	
	printf("Second list without duplicates:\n");
	print_list(cloned);
	printf("\n");
	
	merged = list_merge(&head,&cloned);
	printf("Merged list:\n");
	print_list(merged);
	printf("\n");

	printf("First list after merging:\n");
	print_list(head);
	printf("\n");
	printf("Second list after merging:\n");
	print_list(cloned);
	printf("\n");

	printf("Dropping merged list...\n");
	dropList(&merged);
	printf("Merged list status: ");
	print_list(merged);








	return 0;
}
