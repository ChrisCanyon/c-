#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DirectedGraph {
  public:
    string label;
    vector <DirectedGraph *> connections;
    vector <double> distances;

    DirectedGraph(string label){
      this->label = label;
    }

    void add(DirectedGraph* newNode, double distance){
      connections.push_back(newNode);
      distances.push_back(distance);
    }

    void remove(DirectedGraph* toRemove){
      for(int i = 0; i < connections.size(); i++){
        if (connections.at(i) == toRemove){
          connections.erase(connections.begin() + i);
          // Should also free
        }
      }
    }

    void print(){
      cout<<label<<" is connected to: ";
      for (int i = 0; i < connections.size(); i++){
        cout<<connections.at(i)->label<<", ";
      }
      cout<<endl;
      for (int i = 0; i < connections.size(); i++){
        connections.at(i)->print();
      }
    }
};

int main(){
  DirectedGraph a("a"),b("b"),c("c"),d("d"),e("e"),f("f"),g("g");

  a.add(&b,10);
  b.add(&c, 10);
  b.add(&d, 5);
  a.add(&d, 12);
  d.add(&e, 7);
  e.add(&f, 9);
  e.add(&g,2);

  a.print();

  cout<<"Removing"<<endl;
  a.remove(&d);

  a.print();
}
