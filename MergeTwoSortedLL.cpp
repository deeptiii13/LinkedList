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

void insert(Node* &head, int val){
    Node* nnode = new Node(val);
    if(head == NULL){
        head = nnode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp -> next;
    }
    temp -> next = nnode;
}

Node* merge(Node* h1, Node* h2){
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    Node* head = NULL;
    while(h1!=NULL && h2!=NULL){
        if(h1->val < h2->val){
            insert(head, h1->val);
            h1 = h1 -> next;
        }
        else if(h1->val > h2->val){
            insert(head, h2->val);
            h2 = h2 -> next;
        }
        else{
            insert(head, h1->val);
            insert(head, h2->val);
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
    }
    while(h1 != NULL){
        insert(head, h1->val);
        h1 = h1->next;
    }
    while(h2 != NULL){
        insert(head, h2->val);
        h2 = h2->next;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp -> next;
    }
}


int main(){

    Node* h1 = new Node(2);
    insert(h1, 4);
    insert(h1, 6);
    insert(h1, 8);
    insert(h1, 10);

    Node* h2 = new Node(1);
    insert(h2, 3);
    insert(h2, 5);
    insert(h2, 7);
    insert(h2, 9);

    Node* res = merge(h1,h2);
    print(res);

}