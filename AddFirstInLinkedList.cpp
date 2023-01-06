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

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp -> next;
    }
}

int main(){
    Node* head = new Node(13);
    insertBeg(head, 10);
    insertBeg(head, 7);
    print(head);
}