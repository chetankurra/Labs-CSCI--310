 	#include "Graph.h"

	//function to display the degree of each vertices in the graph
	bool showDegrees(const Graph<unsigned> &G)
	{
		set<unsigned> Vertices = G.getVertices();
		if(G.isGraphDirected()==true)  //for the directed graph displaying in-degree & out-degree
		{
			cout<<setw(10)<<"Vertex";
	 		cout<<setw(10)<<"inDegree";
			cout<<setw(10)<<"outDegree";
			cout<<endl;

			for(auto it=Vertices.begin(); it!=Vertices.end();++it)
			{
				cout<<setw(10)<<(*it);
				cout<<setw(10)<<G.getInDegree((*it));
				cout<<setw(10)<<G.getOutDegree((*it));
				cout<<endl;
			}
		}
		else  //for undirected graph just displaying the degree
		{
			cout<<setw(10)<<"Vertex";
			cout<<setw(10)<<"Degree";
			cout<<endl;

			for(auto it=Vertices.begin(); it!=Vertices.end();++it)
			{
				cout<<setw(10)<<(*it);
				cout<<setw(10)<<G.getDegree((*it));
				cout<<endl;
			}
		}
		return true;
	}