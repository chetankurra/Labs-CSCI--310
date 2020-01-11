#include <iostream>
#include <queue>
using namespace std;

int findMin(queue<int> q){
  int min=q.front();
  while(!q.empty()){
    if(q.front() < min)
    min = q.front();
    q.pop();

  }
  return min;
}


int main ()
{
int cnt=0;
int qint;
queue<int> q;
int min;

  while(cin>>qint)
  {
    cnt++;
    q.push(qint);
  }
min=findMin(q);
cout<<cnt<<" "<<min<<endl;

return 0;
}
