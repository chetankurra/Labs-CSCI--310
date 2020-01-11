#include <iostream>
#include <string>
#include <random>
using namespace std;
#include "Node.h"

  template< class T >
  void insert( Node<T>* &headPtr , const T& entry )
  {
  	// Create a new node and have the next pointer point to current front
  	Node<T> *newNodePtr = new Node<T>( entry , headPtr );
  	// Current front now becomes this new node
  	headPtr = newNodePtr;
  }

  // Template function to display the contents of a linked list
 

  template< class T >
void displayRev( Node<T> *headPtr)
{

    if(headPtr == NULL)
       return;
    displayRev(headPtr->getNext());
    std::cout<< headPtr->getItem()<<" ";
}


template< class T >
int sum( Node<T> *headPtr){
  
    int su=0,xa;
  	Node<T> *currNodePtr = headPtr;
  	while( currNodePtr ) 
  	{
     
       string cal = currNodePtr->getItem();
       xa = std::stoi(cal);
       su = su + xa;
  		currNodePtr = currNodePtr->getNext();
  	}
   
    cout<<endl<< "Sum: "<<su<<endl;
   
   
    return su;
}

template< class T >
int max( Node<T> *headPtr)
{
	Node<T> *currNodePtr = headPtr;
 
  int count=0,maax,toint;
  
  string cal = currNodePtr->getItem();
  toint = std::stoi(cal);
  
  if(count==0){
      maax=toint;
     }
     
  while(currNodePtr!=NULL){
    
    if(toint>maax)
       {
       maax=toint;
       }
      currNodePtr=currNodePtr->getNext();
      count++;
  }
  std::cout<<"Maximum: "<<maax<<endl;
  return maax;
  }   

int main()
{
	// Declare a linked list of strings
	Node<string> *listOfStrings = nullptr;
	// Declare a linked list of ints

	// Read words and insert each one into a linked list
	string word;
	while( cin >> word )
	    insert( listOfStrings , word );
 std::cout<<"Contents: ";
   if(listOfStrings==nullptr){
     cout<<"<EMPTY>"<<endl;
   }
else{
	// Display the contents of the string linked list
	displayRev( listOfStrings );
	// Display the contents of the integer linked list
	//sdisplay<int>( listOfIntegers ); cout << endl;

 sum(listOfStrings); 
 max(listOfStrings);
 
 /*max(listOfStrings);*/
}
 return 0;
}
