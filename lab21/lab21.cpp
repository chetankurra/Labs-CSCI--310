
#include "Graph.h"

int main()
{
    Graph G1, G2;

    unsigned E, u, v;
    cin >> E;

    for (size_t i = 0; i < E; i++)
    {
        cin >> u >> v;
        addEdge(G1, u, v);
    }

    cout << "1st " << G1 << endl;

    cin >> E;
    for (size_t i = 0; i < E; i++)
    {
        cin >> u >> v;
        addEdge(G2, u, v);
    }

    cout << "2nd " << G2 << endl;
    
    
    // union_op(G1,G2);
    // difference_op(G1,G2);

    cout << "Union " << G1 + G2 << endl;
    cout << "Difference " << G1 - G2  << endl;

        return 0;
}