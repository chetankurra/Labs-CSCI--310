#include <iostream>
#include <set>
using namespace std;

template <class T>
void show(set<T> st)
{
  set<int>::iterator it;
  for (it = st.begin(); it != st.end(); ++it)
    cout << " " << *it;
}

template <class T>
void show_reverse(set<T> st)
{
  set<int>::reverse_iterator it;
  for (it = st.rbegin(); it != st.rend(); ++it)
    cout << " " << *it;
}

int main()
{
  set<int> st;
  set<int>::iterator it;
  
  int input;
  while (cin >> input)
  {
    st.insert(input);
  }

  show(st);
  cout << endl;
  show_reverse(st);
  cout << endl;
  return 0;
}