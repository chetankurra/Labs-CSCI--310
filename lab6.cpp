#include <iostream>
#include<vector>

using namespace std;


void baseconvert(unsigned data,unsigned base)
{


  if(data>0)
  {

    if(data/base>0)

    baseconvert( data/base,base );

    if(data%base >= 10 )
    {
      cout<<(char)('A'+(data%base)-10);
      }
    else
    cout<<data%base;
  }
}
int main()
{
  int tobase,limit,integers;
  vector<int> v;
  while(cin>>tobase>>limit)
  {
    for(int i=0;i<limit;i++)
    {
      cin>>integers;
      v.push_back(integers);

    }
    cout<<"Conversion to base-"<<tobase<<":"<<endl;
    for(int i=0;i<limit;i++)
    {
      cout<<"  "<<v.at(i)<<":";
      baseconvert(v.at(i),tobase);
      cout<<endl;
    }
    cout<<endl;
    v.clear();
  }


}
