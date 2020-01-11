#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include<map>

using namespace std;

struct Graph{
    set<unsigned> myset;
    multimap<unsigned,unsigned> mp;
};

typedef Graph tgraph;

void addEdge(Graph &G,int u,int v){
    G.mp.insert(pair<unsigned,unsigned>(u,v));
    G.mp.insert(pair<unsigned,unsigned>(v,u));
    G.myset.insert(v);
    G.myset.insert(u);
}

ostream& operator<< (ostream& stream, Graph &x) {

    int p=0,xp=0; 
    set<unsigned>::iterator it;
      stream<<"Graph has "<<x.myset.size()<<" vertices and "<<x.mp.size()<<" edges.";
      stream<<endl;
      stream<<"  V="<<"{";
    multimap<unsigned,unsigned>::iterator it1;
      for (it=x.myset.begin(); it!=x.myset.end(); ++it){
         if(p == 0){
         stream << *it;
         p =1;
         }
         else
         {
          stream<<"," << *it;
         }
         
      }
      stream<<"}";
      stream<<endl;
    stream<<"  E="<<"{";
     for (it1=x.mp.begin(); it1!=x.mp.end(); ++it1){
         if(xp == 0){
             xp = 1;
                         stream<<"("<<(*it1).first<<","<<(*it1).second<<")";
         }
         else
         {
                        stream<<",("<<(*it1).first<<","<<(*it1).second<<")";

         }
         
     }
 
      stream<<"}";
          
    return stream;  
}
