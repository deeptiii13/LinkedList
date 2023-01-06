#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int num;
        Node* next;
        Node(int val) {
            num = val;
            next = NULL;
        }
};

Node* kReverse(Node* head, int k){
    if(head==NULL){
      return NULL;
    }

    
    Node * prev =  NULL;
    Node * curr = head;
    Node * next = NULL;
    int count = 0;
    while( curr != NULL && count < k){
      next = curr -> next;
      curr -> next  = prev;
      prev =  curr;
      curr = next;
      count++;
    }
    
    if( next != NULL ){
      head -> next = kReverse(next, k);
    }
    
    return prev;
    
}

