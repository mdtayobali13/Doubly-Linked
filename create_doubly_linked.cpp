#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Delete a node at position 'pos' (1-based index)
void deleteNode(Node* &head, int pos) {
    if (!head) return;
    if (pos == 1) {
        Node* deleteHead = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete deleteHead;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 2 && temp->next; i++) {
        temp = temp->next;
    }

    Node* deleteNode = temp->next;
    if (!deleteNode) return;

    temp->next = deleteNode->next;
    if (deleteNode->next) deleteNode->next->prev = temp;
    delete deleteNode;
}

// Delete the tail node
void delete_tail(Node* &tail) {
    if (!tail) return;
    Node* deleteNode = tail;
    tail = tail->prev;
    if (tail) tail->next = NULL;
    delete deleteNode;
}


void delete_head(Node* &head) {
    if (!head) return;
    Node* deleteHead = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete deleteHead;
}

int size(Node * head)
{
    Node * temp = head;

    int cunt = 0;

    while (temp != NULL)
    {
      cunt++;
      temp = temp->next;
    }
    return cunt;
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* tail = d;


    head->next = a;
    a->prev = head;

    a->next = b;
    b->prev = a;

    b->next = c;
    c->prev = b;

    c->next = d;
    d->prev = c;

    int pos ;
    cin>>pos;

    if(pos >= size(head)){
       cout<<"invalid"<<endl;
    }else if(pos == 0)
    {
        delete_head(head);
    }
    else if(pos == size(head)-1){
        delete_tail(head);
    }else{
       deleteNode(head, pos );
    }

    print_list(head);
    print_reverse(tail);

    return 0;
}
