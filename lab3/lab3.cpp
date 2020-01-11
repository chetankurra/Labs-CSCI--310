#include <iostream>
#include "Stats.h"
using namespace std;

int main(){

Stats statistics;
int data;

while( cin >> data ) {
  statistics.update( data );
}

cout << "count   = "<<statistics.getCount() << endl;
cout << "minimum = "<<statistics.getMinimum()<< endl;
cout << "maximum = "<<statistics.getMaximum()<< endl;
cout << "sum     = "<<statistics.getSum() << endl;
cout << "average = "<<statistics.getAverage()<< endl;

return 0;
}
