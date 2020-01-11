#include <iostream>

using namespace std;

#ifndef _STATS_
#define _STATS_

// CLASS SPECIFICATION

// A class that handles basic statistics on a set of integer data.

class Stats
{
	private:
	// DATA MEMBERS /////////////////////////////////////////////////////////
		unsigned count;    // number of data elements processed so far
		int      sum;      // sum of all data elements processed so far
		int      minimum;  // minimum of all data elements processed so far
		int      maximum;  // maximum of all data elements processed so far

	public:
	// MEMBER FUNCTIONS /////////////////////////////////////////////////////

		// CONSTRUCTOR(S) ---------------------------------------------------
		Stats();

		// SET MEMBER FUNCTIONS or MUTATORS ---------------------------------
		void update( int newData );

		// GET MEMBER FUNCTIONS or ACCESSORS --------------------------------
		unsigned getCount();
		int getSum();
		int getMinimum();
		int getMaximum();
		float getAverage();
};

#endif
