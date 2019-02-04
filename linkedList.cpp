#include <iostream>

using namespace std;

class node {
  public:

    node *next;
    node *previous;
    int *valuePtr;

    node(){
      next = NULL;
      previous = NULL;
      valuePtr = NULL;
    }

};

class List {
  public:
    node *head;
    node *root;

    List(){
      head = new node();
      head->previous = head;
      root = head;
    }

    void print(){
      cout<<"printing\n";
      node *n = root->next;
      while (n != NULL){
        cout<<(*(n->valuePtr))<<endl;
        n = n->next;
      }
    }

    void insert(int *ptr){
      node *newNode = new node();
      newNode->previous = head;
      newNode->valuePtr = ptr;
      head->next = newNode;
      head = newNode;
    }

    void pop_front(){
      if(head->previous == head){
        cout<<"List already empty"<<endl;
        return;
      }
      node * newHead = head->previous;
      newHead->next = NULL;
      free(head);
      head = newHead;
    }

    void pop_back(){
      if (root->next == NULL){
        cout<<"List already empty"<<endl;
        return;
      }
      node * toFree = root->next;
      root->next = toFree->next;
      free(toFree);
    }
};

int main(){
  List a;

  int b = 1;
  int c = 3;
  int d = 5;
  int e = 6;

  a.print();
  a.insert(&b);
  a.print();
  a.insert(&c);
  a.print();
  a.insert(&d);
  a.print();
  a.pop_back();
  a.print();
  a.insert(&e);
  a.print();
  a.pop_front();
  a.print();


  return 1;
}
