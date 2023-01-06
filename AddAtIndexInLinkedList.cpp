#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }

};

void insertBeg(Node* &head, int val){
    Node* nnode = new Node(val);
    if(head == NULL){
        head = nnode;
        return;
    }
    nnode -> next = head;
    head = nnode;
}

void insertAtIndex(Node* &head, int val, int index){
    Node* nnode = new Node(val);
    if(head == NULL){
        head = nnode;
        return;
    }
    if(index == 1){
        insertBeg(head, val);
        return;
    }
    Node* temp = head;
    int ctr = 1;
    while(ctr!=(index-1) && temp->next!=NULL){
        temp = temp -> next;
        ctr++;
    }
    if(temp->next==NULL && ++ctr==index-1){
        temp -> next = nnode;
        return;
    }
    nnode -> next = temp -> next;
    temp -> next = nnode;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp -> next;
    }
}

int main(){
    Node* head = new Node(13);
    insertAtIndex(head, 10, 1);
    insertAtIndex(head, 7, 2);
    insertAtIndex(head, 5, 3);
    insertAtIndex(head, 22, 1);
    print(head);
}