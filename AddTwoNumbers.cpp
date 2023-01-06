#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            this->data = val;
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

Node * addTwoLists(Node * first, Node * second) {
  Node * res = NULL;
  Node * temp;
  Node * prev = NULL;
  int carry = 0, sum = 0;
  while (first != NULL || second != NULL) {
    sum = carry;
    sum += first != NULL ? first -> data : 0;
    sum += second != NULL ? second -> data : 0;
    if (sum >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
    sum %= 10;
    temp = new Node(sum);
    if (res != NULL) {
      prev -> next = temp;
    } else {
      res = temp;
    }
    prev = temp;
    if (first) {
      first = first -> next;
    }
    if (second) {
      second = second -> next;
    }
  }

  if (carry > 0)
    temp -> next = new Node(carry);
  return res;
}

Node * reverse(Node * head) {
  if (head == NULL || head -> next == NULL) {
    return head;
  }
  Node * rest = reverse(head -> next);
  head -> next -> next = head;
  head -> next = NULL;
  return rest;
}

Node * solve(Node * list1, Node * list2) {
  list1 = reverse(list1);
  list2 = reverse(list2);
  Node * added = addTwoLists(list1, list2);
  return added;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
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

    Node* res = solve(h1,h2);
    print(res);

}