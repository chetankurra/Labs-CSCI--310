#include<iostream>
    #include<set>
    #include<map>
    #include<iomanip>
    #include<stack>

    using namespace std;
    //structure of graph containing set of vertices and multimap of edges
    struct Graph
    {
      set<unsigned> V;
      multimap<unsigned, unsigned> E;
    };

    //inserting the vertices and edges into the set and multimap respectively
    void addEdge(Graph &G,unsigned u, unsigned v )
    {
      G.V.insert(u);
      G.V.insert(v);
      G.E.insert(pair<unsigned,unsigned>(u,v));
      //G.E.insert(pair<unsigned,unsigned>(v,u));
    }

    Graph transpose(Graph oldG)
    {
      Graph newG;
      for(auto it = oldG.E.begin(); it != oldG.E.end(); ++it)
      {
        unsigned u = it->first;
        unsigned v = it->second;
        addEdge(newG, v,u);
      }
      return newG;
    }

    void fillOrder(unsigned vertex, Graph Gr, map<unsigned, bool> &visited, stack<unsigned> &st)
    {
      //cout<<vertex;
      visited[vertex] = true;  //setting vertex as visited
      for(auto itr = Gr.E.begin(); itr!=Gr.E.end();++itr)
      {
        if(itr->first == vertex && visited[itr->second]==false){
          cout<<itr->second;
        fillOrder(itr->second,Gr,visited,st); 
        }  //recursive call to function 
      }
      st.push(vertex);
    }

    

    //function to find the path from one starting vertex to any random vertex covering all the vertices in path
    void DFSUtil(unsigned vertex, Graph Gra, map<unsigned, bool> &visited)
    {

      visited[vertex] = true;  //setting vertex as visited
      cout<<" "<<vertex;
      for(auto itr = Gra.E.begin(); itr!=Gra.E.end();++itr)
      {
        if(itr->first == vertex && visited[itr->second]==false)
        DFSUtil(itr->second,Gra,visited);   //recursive call to function 
      }

    }


    void printSCCs (Graph G)
    {
      stack<unsigned> st;

      map<unsigned, bool> visited;  //map to keep track of visited vertices
        
      for(set<unsigned>::iterator it=G.V.begin();it!=G.V.end();++it)
      {
        visited.insert(pair<unsigned,double>((*it),false));
      }

      for(auto it=visited.begin();it!=visited.end();++it)
      {
        if(it->second == false)
        fillOrder((it->first),G,visited, st);
      }
         
      Graph gT = transpose(G);
             
      for(auto itr = visited.begin(); itr!=visited.end(); ++itr)
      {
        itr->second = false;
      }

      unsigned c=1;
      while(st.empty() == false)
      {
        unsigned vert = st.top();
       //  cout<<vert;
        st.pop();
               
        
        if(visited[vert]==false)
        {
          cout<<setw(6)<<"SCC ";
          cout<<c<<" =";
          DFSUtil(vert, gT,visited);
          cout<<endl;
          c++;
        }
      }
        
    }

    //overloaded function << to print graph 
    ostream& operator <<(ostream &cout, Graph G)
    {
      cout<<"Graph has "<<G.V.size()<<" vertices and "<<G.E.size()<<" edges."<<endl;
      cout<<setw(5)<<"V={";
      for(set<unsigned>::iterator it=G.V.begin();it!=G.V.end();++it)
      {
        cout<<(*it);
        auto j = it;
        ++j;
        cout<<(j==G.V.end()?"":",");
      }
      cout<<"}"<<endl;

      cout<<setw(5)<<"E={";

      for(auto itr = G.E.begin(); itr!=G.E.end();++itr)
      {
        cout<<"(";
        cout<<(itr->first)<<",";
        cout<<(itr->second)<<")";

        auto k = itr;
        ++k;
        cout<<(k==G.E.end()?"":",");
      }

      cout<<"}";

      return cout;
    }