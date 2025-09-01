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

void insert_any_pos(Node * head , int pos , int val)
{
    Node * newNode = new Node(val);

    Node * temp = head;

    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    newNode->next->prev = newNode;
    newNode->prev = temp;
}

void insert_head(Node * &head, Node * &tail , int val)
{
    Node * newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
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
    Node *head = NULL;
    Node * tail = NULL;


    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *c = new Node(40);
    // Node *d = new Node(50);
    // Node * tail = d;


    // head->next = a;
    // a->prev = head;

    // a->next = b;
    // b->prev = a;

    // b->next = c;
    // c->prev = b;

    // c->next = d;
    // d->prev = c;

  int pos , val;
  cin>>pos >> val;;
  if(pos == 0){
    insert_head(head,tail, val);
  }
  else if(pos>= size(head)){
      cout<<"invalid"<<endl;
   }else {
    insert_any_pos(head, pos , val);
   }

    print_list(head);
    print_reverse(tail);

    return 0;
}
