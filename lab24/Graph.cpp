	#include "Graph.h"

	//constructor to initialize graph object 
	template<class T>
	Graph<T> :: Graph(string name, bool directed)
	{
		isDirected = directed;
		graphName = name;
	}

	//returns vertices 
	template<class T>
	set<T> Graph<T> :: getVertices() const
	{
		return V;
	}

	//returns the true if graph is directed otherwise false
	template<class T>
	bool Graph<T> :: isGraphDirected() const
	{
		return isDirected;
	}

	//function to return in degree of particular vertex in the graph
	template<class T>
	T Graph<T> :: getInDegree(T u) const
	{
		unsigned count = 0;

		for(auto it = E.begin(); it!=E.end(); ++it)
		{
			if(it->second == u)
			count++;
		}

		return count;

	}

	//function to return out degree of particular vertex in the graph
	template<class T>
	T Graph<T> :: getOutDegree(T u) const
	{
		unsigned count = 0;

		for(auto it = E.begin(); it!=E.end(); ++it)
		{
			if(it->first == u)
			count++;
		}
	
		return count;
	
	}

	//function to return degree of undirected graph
	template<class T>
	T Graph<T> :: getDegree(T u) const
	{
		unsigned count = 0;
	
		for(auto it = E.begin(); it!=E.end(); ++it)
		{
			if(it->second == u || it-> first == u)
			count++;
		}
	
		if(count == 0)
		return 0;
		else
		return count/2;
	}

	//adds the edges according to the type of graph
	template <class T>
	bool Graph<T> :: add(T u,T v)
	{
		if(isDirected == true)
		{
			V.insert(u);
			V.insert(v);
			E.insert(pair<T,T>(u,v));
		}
		else
		{
			V.insert(u);
			V.insert(v);
			E.insert(pair<T,T>(u,v));
			E.insert(pair<T,T>(v,u));
		}

		return true;
	}


	//overloaded operator to print the graph
	template <class F>
	ostream& operator <<(ostream &cout,const Graph<F> &G)
	{

		if(G.isDirected == true)
		{
			cout<<"digraph "<<G.graphName;
		}
		else
		{
			cout<<"regular graph "<<G.graphName;
		}

		vector<pair<unsigned,unsigned>> printVect;
		for(auto itr = G.E.begin(); itr!=G.E.end();++itr)
		{
			printVect.push_back(make_pair(itr->first,itr->second));
		}

		sort(printVect.begin(),printVect.end());
		cout<<" has "<<G.V.size()<<" vertices and "<<G.E.size()<<" edges:"<<endl;
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
