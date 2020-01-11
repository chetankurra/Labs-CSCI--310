#include<iostream>
#include<vector>
#include <sstream>

using namespace std;


vector<string> split( const string& s , char delimiter )
    {
        vector<string> tokens;          // vector of tokens
        string token;                   // a single token
        istringstream tokenStream(s);   // an input string stream

        // Tokenize s by grabbing individual tokens
        while( getline( tokenStream , token , delimiter ) )
            tokens.push_back(token);    // add found token

        return tokens;
    }


int ifminheap(vector<int> vect)
{

  unsigned i = vect.size() - 1;
  
  while(i != 0)
  {
      int rootnode = ( i - 1)/2;
      if(rootnode >= 0)
      {
          if( vect[i] >= vect[rootnode])
          i--;
          else
          return rootnode;
      }
  
  }
  
  return 0;


}

int main()
{
    string input;
    vector<string> listOfTokens;
    vector<int> newVector;
    char   delimiter = ' ';
    int data=0;


    while( getline( cin , input ) ) {

        // Use the split() function above to extract tokens
        listOfTokens = split( input , delimiter );

        for(unsigned i=0;i<listOfTokens.size();i++)
        {
          newVector.push_back(stoi(listOfTokens[i]));
        }

        data = ifminheap(newVector);

        if(data==0)
        {
          cout<<"Vector is a min-heap."<<endl;
        }
        else
        {
          cout<<"Min-heap structure property violated at index "<<data<<"."<<endl;
        }

        data=0;
        newVector.clear();
        listOfTokens.clear();


      }

      return 0;


}
