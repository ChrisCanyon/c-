#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
  public:
    int * value = NULL;
    node* left = NULL;
    node* right = NULL;
    node* parent = NULL;

    node(){
    }
};

class BTree{
  public:
    node* root;

    BTree(){
      root = new node(); //empty tree
    }

    void add(int* value){
      cout<<"Adding new value: "<<*value<<endl;
      if (*value == NULL){
        cout<<"Can't add null value";
        return;
      }
      node * newNode = new node();
      newNode->value = value;

      if (root->right == NULL){
        newNode->parent = root;
        root->right = newNode;
        return;
      }

      node * currentNode = root->right;
      while (1) {
        if(*(currentNode->value) < *value){
          // right
          if(currentNode->right == NULL){
            // No existing
            newNode->parent = currentNode;
            currentNode->right = newNode;
            return;
          } else {
            currentNode = currentNode->right;
          }
        } else {
          // left
          if(currentNode->left == NULL){
            // No existing
            newNode->parent = currentNode;
            currentNode->left = newNode;
            return;
          } else {
            currentNode = currentNode->left;
          }
        }
      }
    }


    void print(){
      cout<<"Printing\n";
      if (root->right == NULL){
        printf("empty graph");
        return;
      }
      recursivePrint(root, 0);
      cout<<"done printing\n";
    }

  private:
    void recursivePrint(node * n, int depth){
      if (n == NULL) return;
      printf("Level %d: %*d%d\n", depth, depth, *(n->value));
      recursivePrint(n->right, depth+2);
      recursivePrint(n->left, depth+2);
    }
};

int main(){
  BTree t;
  int a = 10;
  int b = 30;
  int c = 20;
  int d = 1;

  t.add(&a);

  t.print();

  t.add(&b);
  t.print();
  t.add(&c);
  t.print();
  t.add(&d);
  t.print();
}
