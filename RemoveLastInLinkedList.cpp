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

        ~ Node(){
            if(this->next != NULL){
                delete next;
                next = NULL;
            }
        }

};

int removeLast(Node*&head){
    if(head == NULL)
        return -1;
    if(head->next == NULL){
        int d = head -> val;
        head = NULL;
        return d;
    }
    Node* temp = head;
    Node* prev;
    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    int d = temp -> val;
    prev -> next = NULL;
    delete temp;
    return d;
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
    Node* h1 = new Node(15);
    Node* h2 = new Node(17);
    Node* h3 = new Node(19);
    head -> next = h1;
    h1 -> next = h2;
    h2 -> next = h3;
    print(head);
    cout << endl;
    cout << "Deleted value: " << removeLast(head) << endl;
    print(head);
}