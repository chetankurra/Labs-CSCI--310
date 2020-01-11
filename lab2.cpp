#include <vector>
#include <iostream>

using namespace std;
int sum( vector<int> v ){
 int add=0;
for (int i = 0; i < v.size() ; i++){
 add = add + v.at(i);
}
return add;
}

int max( vector<int> v ){
    int max = v.at(0);
    for(int i = 1;i < v.size();i++){

if (v.at(i) > max){
max = v.at(i);
}
}
return max;
}
int min( vector<int> v ){
    int min = v.at(0);
    for(int i = 1;i < v.size();i++){

if (v.at(i) < min){
min = v.at(i);
}
}
return min;
}
float average( vector<int> v ){
    float sum1 = 0;
 for (int i=0; i < v.size(); i++) {
 sum1 += v.at(i);
}

float average1= sum1/v.size();
 return average1;
}
int main() {
vector<int> v;

 int i=0,data;

 while(cin>>data&&i<=100){
       v.push_back(data);
}
cout<< "count    = "<<v.size()<<endl;
cout<< "maximum  = "<<max(v)<<endl;
cout<< "minimum  = "<<min(v)<<endl;
cout<< "sum      = "<<sum(v)<<endl;
cout<< "average  = "<<average(v)<<endl;



	return 0;
}
