#include<iostream>
#include<set>
#include<map>
#include<string>
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

void DFS(unsigned vertex, unsigned pie, Graph Gra, map<unsigned, string> &visited, unsigned &count,map<unsigned,unsigned> &parent,map<unsigned,unsigned> &mark)
{


if(visited[vertex] == "visited")
{
    return;
}


if(visited[vertex]=="unvis")
{
    count++;
    unsigned current = pie;
    while(current!=vertex)
   {
        mark.insert(pair<unsigned,unsigned>(current,count));
        current = parent[current];
    }
    mark.insert(pair<unsigned,unsigned>(vertex,count));
    return;
}
            parent.insert(pair<unsigned,unsigned>(vertex,pie)); 
      visited[vertex] = "unvis"; 
                for(auto itr = Gra.E.begin(); itr!=Gra.E.end();++itr)
                {
                        unsigned flag = 0;

              if(parent[vertex] == itr->second) 
                    {
                            flag = 1;
                        }

                if(itr->first == vertex && flag!=1) 
         {
                    DFS(itr->second,itr->first,Gra,visited,count,parent,mark);
        } 
                }
                visited[vertex] = "visited";

}

void displayCycles(Graph G)
{
map<unsigned, string> visited;  
auto itf = G.V.begin(); 
map<unsigned,unsigned> parent;
map<unsigned,unsigned> mark;
unsigned count = 0;

    for(set<unsigned>::iterator it=G.V.begin();it!=G.V.end();++it)
    {
        visited.insert(pair<unsigned,string>((*it),"White"));
    }

DFS((*itf),0,G,visited,count,parent,mark);

if(count == 0)
{
cout<<"No cycles detected.";
}
else
cout<<count<<" cycles detected."<<endl;

unsigned z=1;

while(z<=count)
{
cout<<"Cycle Number "<<z<<": ";
vector<int> tempV;
for(auto ith = mark.begin();ith!=mark.end();++ith)
{
  if(ith->second == z)
    tempV.push_back(ith->first);

}

for(unsigned c=0; c<tempV.size();c++)
{
    cout<<tempV[c]<<" ";

}
cout<<endl;
tempV.clear();
z++;
}
cout<<endl;

}



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
cout<<(j==G.V.end()?"":",");
}
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