#include <iostream>
#include <vector>
#include "ArrayBag.h"
using namespace std;
    int sum(vector<int> v){
      int sum1=0;
      for(unsigned int i=0;i<v.size();i++){
      sum1 = sum1 + v.at(i);
    }
    return sum1;
    }

int main(){
  ArrayBag<int> arraybag;
  int data;
    while(cin>>data){
    if(arraybag.add(data)!=1){
      std::cout << "Cannot add " << data <<"; bag already has "<< arraybag.getCurrentSize() <<" items in it." << '\n';
    }


    }
    cout<< "The sum of the " << arraybag.getCurrentSize()<<" items in the bag is "<<sum(arraybag.toVector())<<"."<<endl;




}
