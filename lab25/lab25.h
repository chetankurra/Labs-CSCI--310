#include "Graph.h"
	#include <unordered_map>

	void APutil(Graph<string> cityMap, string u, unordered_map<string,bool> &visited, unordered_map<string,unsigned> &discovery, unordered_map<string,unsigned> &low, unordered_map<string,string> &parent,map<string,bool> &articulation)
	{
		static unsigned time=0;
		unsigned children = 0;
		visited[u] = true;
		discovery[u] = low[u] = ++time;

		vector<string> adjecents = cityMap.getAdjecentVertices(u);

		for(unsigned i=0; i<adjecents.size(); ++i)
		{
			string v = adjecents[i];

			if(visited[v] == false)
			{
				children++;
				parent[v] = u;
				APutil(cityMap,v,visited,discovery, low, parent, articulation);
				low[u] = min(low[u],low[v]);

				if(parent[u] == "NIL" && children > 1)
				{
					articulation[u] = true;
				}
				else if(parent[u]!="NIL" && low[v] >= discovery[u])
				{
					articulation[u] = true;
				}
			}
			else if(v!=parent[u])
			{
				low[u] = min(low[u],discovery[v]);
			}
		}

	}

	map<string,bool> findCameras(Graph<string> cityMap)
	{
		unordered_map<string,bool> visited;
		unordered_map<string,unsigned> discovery;
		unordered_map<string,unsigned> low;
		unordered_map<string,string> parent;
		map<string,bool> articulation;

		set<string> cities = cityMap.getVertices();

		for(auto itr=cities.begin(); itr!=cities.end(); ++itr)
		{
			visited.insert(pair<string,bool>((*itr),false));
			parent.insert(pair<string,string>((*itr),"NIL"));
			articulation.insert(pair<string,bool>((*itr),false));
		}

		for(auto it = cities.begin();it!=cities.end();++it)
		{
			if(visited[(*it)] == false)
			{
				APutil(cityMap,(*it),visited,discovery,low,parent,articulation);
			}
		}
		return articulation;

	}