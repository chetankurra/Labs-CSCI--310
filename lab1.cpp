
#include <iostream>
using namespace std;
int count = 0;
int sum( int a[])
 {
 int add = 0;

 for (int i = 0; i < count ; i++){
 add = add + a[i];
 }
 return add;
 }
int max( int a[])
{
int max = a[0];
for(int i = 1;i < count;i++){
if (a[i] > max){
max = a[i];
}
}
return max;
}

int min( int a[])
{

double min = a[0];
for(int i = 1;i < count;i++){
if (a[i] < min){
min = a[i];
}}
return min;}
float average( int a[] ){

float sum1 = 0;
 for (int i=0; i < count; i++) {
 sum1 += a[i];
}

float average1= sum1/count;
 return average1;
}


int main() {
 int arr[100];
 int data;
 int i = 0;
 while(cin>>data){
 arr[i]=data;
 i++;
 }
count = i;

cout << "count   = "<<i << endl;
cout << "minimum = "<<min(arr)<< endl;
cout << "maximum = "<<max(arr)<< endl;
cout << "sum     = "<<sum(arr) << endl;
cout << "average = "<<average(arr)<< endl;

return 0;
}
