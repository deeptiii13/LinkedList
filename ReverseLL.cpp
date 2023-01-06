#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
 
};

void reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

void printRec(Node* head){
    if(head == NULL)
        return;
    cout << head->data << " ";
    printRec(head->next);
}

int main(){
    Node *head = new Node(29);
    head -> next = new Node(22);
    head -> next -> next = new Node(28);
    cout << "Linked List:" << endl;
    printRec(head);
    cout << endl;
    //Function Call
    reverseLL(head);
    cout << "Reversed Linked List:" << endl;
    printRec(head);
}