 #include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

struct Graph
{
    set<unsigned> S;
    multimap<unsigned,unsigned> mymp;
};


typedef Graph tgraph;

void addEdge(Graph &G,int u,int v)
{
    G.mymp.insert(pair<unsigned,unsigned>(u,v));
    G.mymp.insert(pair<unsigned,unsigned>(v,u));
    G.S.insert(v);
    G.S.insert(u);
}
    void DFSUtil(int vertex, Graph G, map<unsigned,bool> &visited)
     { 
    visited[vertex] =true;
          
     
          for(auto itr = G.mymp.begin(); itr!=G.mymp.end(); ++itr)
          {
           // cout<<itr->first<<" "<< vertex<<itr->second; 
        if(itr->first == vertex && visited[itr->second]==false){
    
          DFSUtil(itr->second,G,visited);   
        }
 
          } 

}
 void DFS(Graph G, map<unsigned,bool> &visited) 
{ 

    for (auto it=visited.begin();it!=visited.end();++it) 
    {
    
               if ((*it).second == false) 
            DFSUtil((it->first), G, visited); 
    }
} 

 bool connected(Graph G)
 {
  map<unsigned, bool> visited;
       for(multimap<unsigned, unsigned>::iterator it=G.mymp.begin();it!=G.mymp.end();++it)
       {
         visited.insert(pair<unsigned,double>((*it).second,false));
       }
          /*   for(auto itr=visited.begin();itr!=visited.end();++itr)
      {
        cout<<itr->first<<" "<<itr->second<<endl;
      }*/



      DFS(G,visited);

      unsigned flag=0;
      for(auto itr=visited.begin();itr!=visited.end();++itr)
      {
          if(itr->second==false)
          {
              flag = 1;  
                break;
          }
      }

      if((flag == 0 && G.S.size()!=G.mymp.size()) || G.mymp.empty()==true )
        return true;
      else
        return false;

 }

ostream& operator<< (ostream& oput, Graph &x)
 {

    int p=0,mymap=0;
    set<unsigned>::iterator i;
      oput<<"Graph has "<<x.S.size()<<" vertices and "<<x.mymp.size()<<" edges.";
      oput<<endl;
      oput<<"  V="<<"{";

      for (i=x.S.begin(); i!=x.S.end(); ++i)
      {
         if(p == 0){
         oput << *i;
         p =1;
         }
         else
         {
          oput<<"," << *i;
         }
         
      }
      oput<<"}";
      oput<<endl;
      oput<<"  E="<<"{";
      multimap<unsigned,unsigned>::iterator j;
     for (j=x.mymp.begin(); j!=x.mymp.end(); ++j)
     {
         if(mymap == 0)
         {
             mymap = 1;
                         oput<<"("<<(*j).first<<","<<(*j).second<<")";
         }
         else
         {
                        oput<<",("<<(*j).first<<","<<(*j).second<<")";

         }
         
     }
 
      oput<<"}";
          
    return oput;  
}