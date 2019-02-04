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

    void print(){
      cout<<label<<" is connected to: ";
      for (int i = 0; i < connections.size(); i++){
        cout<<connections.at(i)->label<<", ";
      }
      cout<<endl;
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
  b.print();
  c.print();
  d.print();
  e.print();
  f.print();
  g.print();

}
