#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
using namespace std;




int main ()
{
  priority_queue <int, vector<int>, greater<int> > pq;
  priority_queue <int, vector<int>,less<int> > qq;
    int data;

    while (cin>>data){
        pq.push(data);
         qq.push(data);
    }
    while (!pq.empty())
  {
      cout<<' '<< pq.top();
    
     pq.pop(); 
  }
  cout<<endl;
   while (!qq.empty())
  {
      cout<<' '<<qq.top();

     qq.pop(); 
  }
  cout<<endl;

}