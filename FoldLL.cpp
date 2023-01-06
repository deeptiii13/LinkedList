#include <iostream> 
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void build(struct node** head, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void print(struct node* head)
{
	struct node* ptr = head;
	while (ptr)
	{
		cout<<ptr->data <<" ";
		ptr = ptr->next;
	}
}

struct node* newNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void fold(node** head)
{ 
     
    node *slow = *head, *fast = slow->next; 
    while (fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
    struct node* head1 = *head; 
    struct node* head2 = slow->next; 
    slow->next = NULL;

    reverselist(&head2);
  
   
    *head = newNode(0); 
  
    node* curr = *head; 
    while (head1 || head2) { 
        if (head1) { 
            curr->next = head1; 
            curr = curr->next; 
            head1 = head1->next; 
        } 
  
        if (head2) { 
            curr->next = head2; 
            curr = curr->next; 
            head2 = head2->next; 
        } 
    } 
  
    *head = (*head)->next; 
} 

void reverselist(node** head) 
{ 
    node *prev = NULL, *curr = *head, *next; 
  
    while (curr) { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
  
    *head = prev; 
}

int main(void)
{
    int n,k;
	cout<<"Enter size of linked list\n";
	cin>>n;
	int data[100];
	cout<<"Enter linked list data\n";
	for(int i=0;i<n;i++) { cin>>data[i];
	}
	

	struct node* head = NULL;
    
	//constructing linked list
	for (int i = n-1; i >= 0; i--)
		build(&head, data[i]);
	cout<<"\nLinked List Data: ";	
    print(head);
    
	fold(&head);
	cout<<"\nLinked list after folding\nLinked List Data: ";
	print(head);

	return 0;
}

