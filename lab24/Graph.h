 
	#ifndef GRAPH_H_
		#define GRAPH_H_

		#include<iostream>
		#include<set>
		#include<map>
		#include<string>
		#include<iomanip>
		#include<vector>
		#include<algorithm>


		using namespace std;

		template <class T>
		class Graph
		{
			private:
			set<T> V;
			multimap<T,T> E;
			bool isDirected;
			string graphName;

			public:
			Graph(string name, bool directed=0);
			bool add(T,T);
			T getInDegree(T) const;
			T getOutDegree(T) const;
			T getDegree(T) const;
			set<T> getVertices() const;
			bool isGraphDirected() const;
			template<class F>
			friend ostream& operator <<(ostream &cout, const Graph<F> &G);		
		};

		#include "Graph.cpp"
	#endif