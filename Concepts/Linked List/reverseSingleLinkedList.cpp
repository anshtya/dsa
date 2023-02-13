#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
void displayList(Node& head){
    Node *p = &head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseList(Node* head){
    
    Node *prev = NULL;
    Node *curr = head;
    Node *forw = NULL;

    while(curr != NULL){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
}

void recursiveList(Node* head, Node* prev = NULL){
    if (head == NULL) { return; }
    Node* curr = head;
    Node* forw = curr->next;
    curr->next = prev;
    recursiveList(forw, curr);
}

int main(){

    Node n1(2), n2(3), n3(4);
    n1.next = &n2;
    n2.next = &n3;
    displayList(n1);

    //iterative
    // reverseList(&n1);
    // displayList(n3);

    //recursive
    recursiveList(&n1);
    displayList(n3);
    
    return 0;
}