#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <iterator>
#include <utility>
#include <string>

using namespace std;

template <typename T1, typename T2>
set<pair<T1, T2>> cartesianProduct(set<T1> vector1, set<T2> vector2)
{
  set<pair<T1, T2>> S;
  pair<T1, T2> R;
  for (auto i = vector1.begin(); i != vector1.end(); ++i)
  {
    R.first = *i;
    for (auto j = vector2.begin(); j != vector2.end(); ++j)
    {
      R.second = *j;
      S.insert(R);
    }
  }
  return S;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &s, const set<pair<T1, T2>> bravo)
{
  int counter = 0;
  for (auto it2 = bravo.begin(); it2 != bravo.end(); ++it2)
  {
    if(counter==1){
      s << ",(" << it2->first << ",";
      s << it2->second << ")";
    }
    else{
    s << "(" << it2->first << ",";
    s << it2->second << ")";
    counter = 1;
    }

  }
  return s;
}

template <class T>
ostream &operator<<(ostream &s, const set<T> alpha)
{
   int x = 0;
  for (auto ita = alpha.begin(); ita != alpha.end(); ++ita)
  {
    if(x==1){
          s << "," <<*ita;
    }
    else{
          s << *ita;
          x = 1;
    }
  }
  return s;
}

vector<string> split(const string &s, char delimiter)
{
  vector<string> tokens;        // vector of tokens
  string token;                 // a single token
  istringstream tokenStream(s); // an input string stream

  // Tokenize s by grabbing individual tokens
  while (getline(tokenStream, token, delimiter))
    tokens.push_back(token); // add found token

  return tokens;
}

int main()
{
    vector<int> v;  
    string input;                 // input string to hold 1 line from cin
    char   delimiter = ' ';      // what separates tokens in the input string
    vector<string> listOfTokens;  // store tokens of input here
    vector<string> listOfTokens2;  // store tokens of input here
    string a[30];
    int b[30];
    int counter=0;
    set<string> A;
    set<int> B;
    
    while( getline( cin , input ) ) {

        if(counter == 0 ){
           listOfTokens = split( input , delimiter );
        for(int i=0;i<listOfTokens.size();i++){
            a[i]=(listOfTokens.at(i));
            A.insert(a[i]);
        }

          }
        else{
           listOfTokens2 = split( input , delimiter );
        for(unsigned j=0;j<listOfTokens2.size();j++){
            b[j]=stoi(listOfTokens2.at(j));
            B.insert(b[j]);
        }
            counter=0;

        cout << "Given: A={" << A << "}" << endl;
        cout << "       B={" << B << "}" << endl;

        cout << "Then AxB={";
        set<pair<string, int>> first = cartesianProduct(A, B);
        cout << first << "}";
        cout << endl;

        cout << "     BxA={";
        set<pair<int, string>> second = cartesianProduct(B, A);
        cout << second << "}";
        cout << endl;

      
       continue;
        }
           counter++;
    }

}