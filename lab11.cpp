#include <iostream>
#include <queue>
#include <stack>
using namespace std;


template <class T>
void reverse(queue<T> &q)
{
  stack<T> s;
while(!q.empty()){

  s.push(q.front());
  q.pop();
}

while (!s.empty()) {

       q.push(s.top());
       s.pop();
     }
   }
          template <class T>
       void show(queue<T> &q){
         queue<T> qb =  q;
       while (!qb.empty()) {
        cout << qb.front() << endl;
        qb.pop();
    }

   }




int main ()
{

  int qint;
  queue<int> q;
  while(cin>>qint)
  {

    q.push(qint);
  }

show(q);
cout<<endl;
reverse(q);
show(q);

}
