#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


void length(ListNode* head, int &n){
        if(head == NULL){
            return;
        }
        n++;
        length(head->next,n);
    }

ListNode* middle(ListNode* head, int &n, int length){
        if(head == NULL){
            return NULL;
        }
        ListNode* ans = middle(head->next, n, length);
        if(n == length/2+1)
            ans = head;
        n-=1;
        return ans;
    }

ListNode* middleNode(ListNode* head) {
        int n = 0;
        length(head, n);
        int ctr = 0;
        return middle(head, n, n);
        
    }


int main(){
    ListNode* head = new ListNode(29);
    ListNode* h1 = new ListNode(22);
    ListNode* h2 = new ListNode(28);
    ListNode* h3 = new ListNode(13);
    ListNode* h4 = new ListNode(18);
    head -> next = h1;
    h1 -> next = h2;
    h2 -> next = h3;
    h3 -> next = h4;
    ListNode* middle = middleNode(head);
    cout << "Middle Element: " << middle -> val;
}