#include "Graph.h"

 int main()
 {
 Graph G;
 unsigned E,u,v;

 // Add edges to graph G1
 cin >> E; // number of edges in G1
 for( unsigned i=0 ; i<E ; i++ )
 {
 cin >> u >> v;
 addEdge( G , u , v );
 }
 // Display graph G
 cout  << G << endl;

 displayCycles( G );

 return 0;
 }