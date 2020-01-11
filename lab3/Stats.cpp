#include <iostream>
#include "Stats.h"
using namespace std;
int data;
// CLASS IMPLEMENTATION

Stats::Stats()
{
	count=0;
	sum=maximum=minimum=0;
}

void Stats::update(int  data)
{

	int i;
	i=data;

if(count==0){
	minimum = data;
	maximum =data;
}
	sum=sum+i;
	count=count+1;

	if(i > maximum){
		maximum = i;
	}

	if(i < minimum){
		minimum = i;
	}

}

unsigned Stats::getCount()
{
	return count;
}

int Stats::getSum()
{
return sum;
 }



int Stats::getMinimum()
{
return minimum;
}


int Stats::getMaximum()
{
return maximum;

}

float Stats::getAverage()
{
	float s = float(sum);
	float c = float(count);
	float avg = s/c;

   return avg;
}
