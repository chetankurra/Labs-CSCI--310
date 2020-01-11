#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool firasc(const tuple<int, int> &a,
               const tuple<int, int> &b)
{
    return (get<0>(a) < get<0>(b));
}
bool firdes(const tuple<int, int> &a,
               const tuple<int, int> &b)
{
    return (get<0>(a) > get<0>(b));
}

bool secasc(const tuple<int, int> &a,
               const tuple<int, int> &b)
{
    return (get<1>(a) < get<1>(b));
}
bool secdes(const tuple<int, int> &a,
               const tuple<int, int> &b)
{
    return (get<1>(a) > get<1>(b));
}


int main()
{
    string cal;
    int tok;
    int i = 0;
    int data;
    char delimiter = ' ';
    vector<tuple<int, int> > v;
    tuple<int, int> tple;
    //vector<string> v;
    int chetan;
    int c=0;

    while (cin>>data)
    {
      
        if(c==0){
            chetan = data;
            c++;  
        }
        else if(c==1){
             tok = data;
             tple = make_tuple(chetan,tok);
             v.push_back(tple);
             c=0;
        }
    }

   /* for (int i = 0; i <v.size(); i++)
        {
            cout <<"("<< get<0>(v.at(i)) <<","<< get<1>(v.at(i)) <<")";
            cout<<" ";            
        }*/


        
       for (unsigned i = 0; i < v.size(); i++){
             sort(v.begin(), v.end(), firasc); 

        }
        for (unsigned i = 0; i < v.size(); i++)
            {

                cout <<"("<< get<0>(v[i]) <<","<< get<1>(v[i]) <<")";
              cout<<" ";

               
            }
 cout<<endl;


             for (unsigned i = 0; i < v.size(); i++){
             sort(v.begin(), v.end(), firdes);
        }


         for (unsigned i = 0; i < v.size(); i++)
            {

                cout <<"("<< get<0>(v[i]) <<","<< get<1>(v[i]) <<")";
              cout<<" ";
               
            }
             cout<<endl<<endl;
                for (unsigned i = 0; i < v.size(); i++){
             sort(v.begin(), v.end(), secasc); 

        }
        for (unsigned i = 0; i < v.size(); i++)
            {

                cout <<"("<< get<0>(v[i]) <<","<< get<1>(v[i]) <<")";
              cout<<" ";

               
            }
 cout<<endl;


             for (unsigned i = 0; i < v.size(); i++){
             sort(v.begin(), v.end(), secdes);
        }

         for (unsigned i = 0; i < v.size(); i++)
            {

                cout <<"("<< get<0>(v[i]) <<","<< get<1>(v[i]) <<")";
              cout<<" ";
               
            }
    
cout<<endl<<endl;
         v.clear();
        
    
    return 0;
}