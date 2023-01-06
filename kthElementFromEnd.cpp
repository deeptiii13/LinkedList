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

int kthLast(Node* head, int &k){
    if(head == NULL)
        return -1;
    int ans = kthLast(head->next, k);
    k-=1;
    if(k==0){
        ans = head->val;
    }
    return ans;
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
    Node* h4 = new Node(21);
    head -> next = h1;
    h1 -> next = h2;
    h2 -> next = h3;
    h3 -> next = h4;
    int k = 2;
    print(head);
    cout << endl;
    int ans = kthLast(head, k);
    cout << "kth element from end: " << ans << endl;
}