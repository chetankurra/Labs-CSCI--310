

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
   private:
      ItemType        item; // A data item
      Node<ItemType>* next; // Pointer to next node
      Node<ItemType>* prev;
   public:
      Node();
      Node(const ItemType& anItem);
      Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
      void setItem(const ItemType& anItem);
      void setNext(Node<ItemType>* nextNodePtr);
      void setprev(Node<ItemType>* prevNodePtr);
      ItemType getItem() const ;
      Node<ItemType>* getNext() const ;
      Node<ItemType>* getPrev() const ;
}; // end Node

#include "Node.cpp"
#endif
