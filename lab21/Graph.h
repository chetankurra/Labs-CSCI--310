    #include <iostream>
    #include <utility>
    #include <set>
    #include <map>
    #include <algorithm>
    #include <iomanip>
    #include <vector>


    using namespace std;

    struct Graph 
    {
    set<unsigned> V;
    multimap<unsigned, unsigned> E;
    };

    typedef Graph GX; 

    void addEdge(Graph &G, unsigned u, unsigned V) 
    {
    G.V.insert(u);                              
    G.V.insert(V);                              
    G.E.insert(pair<unsigned, unsigned>(u, V));
    G.E.insert(pair<unsigned, unsigned>(V, u));
    }

       Graph &operator-(Graph &G1, Graph &G2)
    {
    std::set<unsigned>::iterator iter, iter2, it3;
    for (iter = G2.V.begin(); iter != G2.V.end(); ++iter) 
    {
    for (iter2 = G1.V.begin(); iter2 != G1.V.end(); ++iter2)
    {
    if (*iter == *iter2)
    {
    G1.V.erase(*iter2); 
    }
    }
    }

    std::multimap<unsigned, unsigned>::iterator itr, itr1;

    for (itr1 = G2.E.begin(); itr1 != G2.E.end(); ++itr1) 
    {

    for (itr = G1.E.begin(); itr != G1.E.end(); ++itr)
    { 
    if (((*itr).first == (*itr1).first && (*itr).second == (*itr1).second))
    {
    G1.E.erase(itr); 
    }
    }
    }

    vector<pair<unsigned, unsigned>> finalE;
    for (itr = G1.E.begin(); itr != G1.E.end(); ++itr)
    {

    bool is_in = G1.V.find((*itr).first) != G1.V.end();
    bool is_in1 = G1.V.find((*itr).second) != G1.V.end();
    if (is_in1 == true && is_in == true) 
    {
    finalE.push_back(pair<unsigned, unsigned>((*itr).first, (*itr).second));
    }
    }
    G1.E.clear();
    for (size_t i = 0; i < finalE.size(); i++)
    {
    G1.E.insert(pair<unsigned, unsigned>(finalE[i].first, finalE[i].second));
    }

    return G1;
    }


    Graph &operator+(Graph &G1, Graph &G2)
    {
    std::set<unsigned>::iterator iter, iter2;
    for (iter = G2.V.begin(); iter != G2.V.end(); ++iter) 
    {
    G1.V.insert(*iter);
    }
    std::multimap<unsigned, unsigned>::iterator itr, itr1;
    int marker = 0;
    for (itr = G2.E.begin(); itr != G2.E.end(); ++itr)
    {                                                        
    for (itr1 = G1.E.begin(); itr1 != G1.E.end(); ++itr1) 
    {
 
    if ((*itr).first == (*itr1).first && (*itr).second == (*itr1).second)
    {
        marker = 1;
    }
    }
    if (marker != 1)
    {
    G1.E.insert(pair<unsigned, unsigned>((*itr).first, (*itr).second)); 
    }
    marker = 0;
    }
    return G1; 
    }


 

    ostream &operator<<(ostream &stream, Graph &c)
    {
    std::multimap<unsigned, unsigned>::iterator iter2;
    vector<pair<unsigned, unsigned>> output;

    for (iter2 = c.E.begin(); iter2 != c.E.end(); ++iter2) 
    {
    output.push_back(pair<unsigned, unsigned>(iter2->first, iter2->second));
    }
    std::sort(output.begin(), output.end(), [](const pair<unsigned, unsigned> &l, const pair<unsigned, unsigned> &r) {
    if (l.first < r.first)
    {
    return l.first < r.first;
    }
    else if (l.first == r.first) 
    {
    if (l.second != r.second)
        return l.second < r.second;

    return l.first < r.first;
    }
    return l.first < r.first;
    });

    stream << "Graph has " << c.V.size() << " vertices and " << c.E.size() << " edges." << endl;

    stream << "  V={";
    int c1 = 0, c2 = 0;
    std::set<unsigned>::iterator iter;
    for (iter = c.V.begin(); iter != c.V.end(); ++iter) 
    {
    if (c1 == 0)
    {
    stream << (*iter);
    c1 = 1;
    }
    else
    {
    stream << "," << (*iter);
    }
    }
    stream << "}" << endl;

    stream << "  E={";

    for (size_t i = 0; i < output.size(); i++)
    {
    if (c2 == 0)
    {
    c2 = 1;
    stream << "(" << output[i].first << "," << output[i].second << ")";
    }
    else
    {
    stream << ",(" << output[i].first << "," << output[i].second << ")";
    }
    }

    stream << "}";

    return stream;
    }
