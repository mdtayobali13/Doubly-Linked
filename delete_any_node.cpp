#include<bits/stdc++.h>
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

void delete_any_pos(Node* head , int pos)
{
    Node * temp = head;

    for (int i = 0; i < pos-1; i++)
    {
       temp = temp->next;
    }
    Node* deleteNode = temp->next;

    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete deleteNode;
    
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

void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse(Node *tail) {
    Node *temp = tail;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node * tail = d;

    print_list(head);
    int pos;
    cin>>pos;

    delete_any_pos(head, pos);
 
    print_list(head);
    // print_reverse(tail);

    return 0;
}
