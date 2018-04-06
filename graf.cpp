#include <iostream>
using namespace std;

//pojemnik/obiekt
struct graphContainer{
  int v;
  graphContainer * next ;
};

int main(){
  int vertex ,edge;
  graphContainer **newGraphContainer;
  int dg = 0, dv, v, u;
  graphContainer *p;

  cout << "Podaj ilosc wierzcholkow i krawedzi: ";
  cin >> vertex >> edge;

  newGraphContainer = new graphContainer * [vertex];
  for(int i = 0; i < vertex; i++){
    newGraphContainer[i] = NULL;
  }

  for(int i = 0; i < edge; i++){
    cin >> v >> u;
    p = new graphContainer;
    p->v = u;
    p->next = newGraphContainer[v];
    newGraphContainer[v] = p;

    if(v != u){
      p = new graphContainer;
      p->v = v;
      p->next = newGraphContainer[u];
      newGraphContainer[u] = p;
    }
  }

   for(v = 1; v <= vertex; v++){
    dv = 0;
    for(p = newGraphContainer[v]; p; p = p->next){
      if(p->v == v) dv += 2;
      else dv++;
    }
    cout << "Stopien wierzcholka " << v << " to " << dv << endl;
    dv = 0;
    }

  for(v = 1; v <= vertex; v++){
    dv = 0;
    for(p = newGraphContainer[v]; p; p = p->next){
      if(p->v == v) dv += 2;
        else dv++;
      if(dv > dg) dg = dv;
    }
  }

  cout << endl <<"Maksymalny stopien grafu to: " << dg << endl;
  return 0;
}
