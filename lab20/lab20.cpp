#include "Graph.h"

 int main()
 {
 Graph G;


 unsigned u,v;
 while( cin >> u >> v )
 addEdge( G , u , v );

 
 cout << G << endl;

 cout << "Here are the strongly connected components:" << endl;
 printSCCs( G );

 return 0;
 }