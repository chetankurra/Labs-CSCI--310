#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main ()
{
  stack <char> charStack;
  string w;

  while(cin>>w){


    for (unsigned int i = 0; i < w.length(); i++)
    {
      if(i==0){
          std::cout << "\"";
      }

      if(w[i]=='a'){

        if(charStack.empty() || charStack.top() == 'a')
          charStack.push('a') ;

        }

        if(w[i]=='b'){
          if(charStack.empty() || charStack.top() == 'b')
            charStack.push('b') ;

          }

          if(w[i]=='b'){
            if( !charStack.empty() && charStack.top() == 'a')
              charStack.pop() ;
            }

            if(w[i]=='a'){
              if(!charStack.empty() && charStack.top() == 'b')
                charStack.pop() ;
              }


            cout<<w[i];
            }
            if(charStack.empty()){
              std::cout <<"\"" ;
                  cout<<" "<<"accepted"<<endl;
                }
                else{
                  std::cout <<"\"" ;
                  cout<<" "<<"REJECTED"<<endl;

                }
                while(!charStack.empty()){
                  charStack.pop();

                }
          }

      return 0;
    }
