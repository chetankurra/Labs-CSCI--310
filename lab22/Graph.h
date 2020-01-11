#include<iostream>
    #include<set>
    #include<map>
    #include<iomanip>
    #include<stack>
    #include<vector>
    #include<algorithm>

    using namespace std;
    
    struct Graph
    {
      set<unsigned> V;
      multimap<unsigned, unsigned> E;
    };


    void addEdge(Graph &G,unsigned u, unsigned v )
    {
      G.V.insert(u);
    
        G.V.insert(v);
      G.E.insert(pair<unsigned,unsigned>(u,v));
         G.E.insert(pair<unsigned,unsigned>(v,u));
    }

  
    bool edgeexist(Graph G, unsigned u, unsigned v)
    {


     for(auto it = G.E.begin(); it != G.E.end(); ++it)
     
     
      {
        if(it->first == u)
    {

          if(it->second == v)
             return true;
        } }

      return false;
    }

    Graph operator-(Graph G1,Graph G2)
    {
     Graph G3;
      G3.V = G1.V;
      G3.E = G1.E;

      for(auto it = G2.V.begin(); it!=G2.V.end(); ++it)
   {
        for(auto itrd = G3.V.begin();itrd!=G3.V.end();++itrd)
        {
       if((*it)==(*itrd))
          {
            G3.V.erase(itrd); 
             
        for(auto itx=G3.E.begin();itx!=G3.E.end();++itx)
            {
              if(itx->first == (*it) || itx->second == *it)
              {
            G3.E.erase(itx);
              }
        }
          }} }

    
      for(auto itf=G2.E.begin(); itf!= G2.E.end(); ++itf)
      {
    for(auto ith=G3.E.begin();ith!=G3.E.end();++ith)
     {
      // cout<<itf->second<<"ooo"<<endl;
          if(itf->first == ith->first && itf->second == ith->second)
      {
            G3.E.erase(ith);  
          }
        }
      }

      return G3;
    }

    Graph operator *(Graph G1,Graph G2)
    {

      Graph G3;


      for(auto itr = G1.V.begin();  itr != G1.V.end(); ++itr)
      {
        for(auto itrd = G2.V.begin(); itrd!= G2.V.end();++itrd)
        {
             if((*itrd) == (*itr))
          {   
              G3.V.insert((*itrd));
         
          }
        }
         }
      for(auto it = G1.E.begin(); it!=G1.E.end(); ++it) 
      {

          if(edgeexist(G2, it->first, it->second) == true && edgeexist(G3, it->first, it->second) == false)
          {
            addEdge(G3, it->first, it->second);
          }

      }

      return G3;

    }
    Graph operator +(Graph G1,Graph G2)
    {
      Graph G3;

      for(auto it = G1.E.begin(); it!=G1.E.end();++it) 
      {
        if(edgeexist(G3, it->first, it->second) == false)
        addEdge(G3,it->first,it->second);
 }

      for(auto itr = G2.E.begin();itr!=G2.E.end();++itr)      {
        if(edgeexist(G3, itr->first, itr->second) == false)
        {
          addEdge(G3,itr->first,itr->second); }
      }

      return G3;  }

    ostream& operator <<(ostream &cout, Graph G)
    {
      vector<pair<unsigned,unsigned>> printVect;
      for(auto itr = G.E.begin(); itr!=G.E.end();++itr)
      {
          printVect.push_back(make_pair(itr->first,itr->second));
      }

      sort(printVect.begin(),printVect.end());
      cout<<"Graph has "<<G.V.size()<<" vertices and "<<G.E.size()<<" edges."<<endl;
      cout<<setw(5)<<"V={";
      for(set<unsigned>::iterator it=G.V.begin();it!=G.V.end();++it)
      {
        cout<<(*it);
        auto j = it;
           ++j;
        cout<<(j==G.V.end()?"":","); }
        cout<<"}"<<endl;

      cout<<setw(5)<<"E={";

      for(auto itr = printVect.begin(); itr!=printVect.end();++itr)
      {
        cout<<"(";
        cout<<(itr->first)<<",";
        cout<<(itr->second)<<")";

        auto k = itr;
        ++k;
        cout<<(k==printVect.end()?"":",");
      }

      cout<<"}";
      return cout;
    }