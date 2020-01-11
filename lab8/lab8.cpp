

	#include <iostream>
	#include <string>
	#include <random>    

	using namespace std;

	#include "Node.h"

	template< class T >
	void insert( Node<T>* &headPtr , const T& entry )
	{
		Node<T> *currNodePtr = headPtr;

	 if (headPtr == NULL || headPtr->getItem() >= entry)
	 {
		 Node<T> *newNodePtr = new Node<T>( entry , headPtr );
			 newNodePtr->setprev(headPtr);
			 headPtr = newNodePtr;
	 }
	 else
	 {

			 currNodePtr = headPtr;
			 while (currNodePtr->getNext()!=NULL && currNodePtr->getNext()->getItem() < entry)
			 {

					 currNodePtr = currNodePtr->getNext();
			 }
			 Node<T> *newNodePtr = new Node<T>( entry ,  currNodePtr->getNext() );
			 currNodePtr->setNext(newNodePtr);
	 }
	}


template <class T>
void display(Node<T> *headPtr)
{ 
  Node<T> *currNodePtr = headPtr;
  while (currNodePtr)
  {
    cout << " " << currNodePtr->getItem();
    currNodePtr = currNodePtr->getNext();
  }
  cout<<endl;
}
/*
 template< class T>
	 void deletenode(Node<T> *headPtr,Node<T> *currNodePtr)
	 {

		 if(headPtr==currNodePtr && currNodePtr->getNext()!=NULL){
			 headPtr = currNodePtr -> getNext();
			 free(currNodePtr);
			 return;
		 }
		 else {
			 Node<T> *prevNodePtr=headPtr;
			 while(prevNodePtr->getNext() != NULL &&  prevNodePtr->getNext() != currNodePtr)
	       prevNodePtr = prevNodePtr->getNext();

				 if(prevNodePtr->getNext() ==NULL)
				 {
					  return;
				 }
				 prevNodePtr->setNext(prevNodePtr->getNext()->getNext());
				 free(currNodePtr);
			 }

		 }
*/
template <class T>
int displayOdd(Node<T> *headPtr)
{
  int flag=0;
  Node<T> *currNodePtr = headPtr; 

  while (currNodePtr)
  {
  if (currNodePtr->getItem()%2 != 0)
    {
      flag++;
      cout<<" ";
      cout<<currNodePtr->getItem();
    }
    currNodePtr = currNodePtr->getNext(); 
  }
  cout<<endl;
  return flag;
}

template <class T>
int countEvn(Node<T> *headPtr)
{
  int flag2=0;
  Node<T> *currNodePtr = headPtr;
  while (currNodePtr)
  {
  if (currNodePtr->getItem()%2 == 0)
    {
      flag2++;


    }
    currNodePtr = currNodePtr->getNext(); 
  }
  return flag2;
}
int main()
  {
  Node<int> *listOfIntegers = nullptr;

  int num;
  int flag2;
  int inputs=0;

  while (cin >> num){
    inputs++;
    insert(listOfIntegers, num);
  }
  cout<<"Sorted list (" <<inputs<< " elements):"<<endl;
  display(listOfIntegers);
  flag2=countEvn(listOfIntegers);
  cout<<"Found "<<flag2<<" even numbers"<<endl;

  cout<<"List with even numbers removed ("<<(inputs-flag2)<<" elements):"<<endl;
  displayOdd(listOfIntegers);
  return 0;
}
